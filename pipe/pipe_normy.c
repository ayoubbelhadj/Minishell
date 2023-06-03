/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_normy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:41:09 by aoudija           #+#    #+#             */
/*   Updated: 2023/05/30 17:48:47 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*builtinnot_path(t_cmd *cmd)
{
	char	*s;

	s = NULL;
	if (!is_builtin(cmd))
	{
		s = grant_access(cmd);
		if (!s)
			exit(g_data.exit_status);
	}
	return (s);
}

void	d_n_c_first(t_cmd *cmd, int **fd, int i)
{
	dup2(cmd->in, 0);
	dup2(cmd->out, 1);
	close(fd[i][0]);
	dup2(fd[i][1], cmd->out);
	close(fd[i][1]);
}

void	d_n_c_last(t_cmd *cmd, int **fd, int i)
{
	dup2(cmd->in, 0);
	close(fd[i][1]);
	dup2(fd[i][0], cmd->in);
	dup2(cmd->out, 1);
	close(fd[i][0]);
}

void	d_n_c_middle(t_cmd *cmd, int **fd, int i)
{
	dup2(cmd->in, 0);
	dup2(cmd->out, 1);
	close(fd[i][0]);
	dup2(fd[i - 1][0], cmd->in);
	dup2(fd[i][1], cmd->out);
	close(fd[i][1]);
	close(fd[i - 1][0]);
}

void	exec_command(t_cmd *cmd, char *s, char **envv)
{
	if (cmd->out != -1 && cmd->in != -1)
	{
		if (is_builtin(cmd))
		{
			exec_builtin(cmd);
			exit(g_data.exit_status);
		}
		else
		{
			execve(s, cmd->args, envv);
			exit(g_data.exit_status);
		}
	}
	else
		exit(g_data.exit_status);
}
