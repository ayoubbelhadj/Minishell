/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:13:14 by aoudija           #+#    #+#             */
/*   Updated: 2023/05/30 13:50:41 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	pipe_it(t_cmd *cmd, char **envv)
{
	int		**fd;
	int		i;
	t_cmd	*tmp;

	tmp = cmd;
	fd = malloc(sizeof(int *) * (cmd_list_size(cmd) - 1));
	i = cmd_list_size(cmd) - 2;
	while (i >= 0)
	{
		fd[i] = malloc(sizeof(int) * 2);
		i--;
	}
	i = 0;
	while (cmd->next)
	{
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
		first_cmd(cmd, fd, &i, envv);
		cmd = cmd->next;
		last_cmd(cmd, fd, &i, envv);
		middle_cmd(cmd, fd, &i, envv);
	}
	close_fdeez(tmp, fd);
}

void	fork_n_exec(t_cmd *cmd, char *s, char **envv)
{
	int	pid;

	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	pid = fork();
	if (!pid)
	{
		signal(SIGQUIT, SIG_DFL);
		signal(SIGINT, SIG_DFL);
		dup2(cmd->in, 0);
		dup2(cmd->out, 1);
		execve(s, cmd->args, envv);
		exit(g_data.exit_status);
	}
	else
	{
		waitpid(pid, &g_data.exit_status, 0);
		if (WIFSIGNALED(g_data.exit_status))
			g_data.exit_status += 128;
		else
			g_data.exit_status %= 255;
		free(s);
		ft_free(envv);
		return ;
	}
}

void	execute_it(t_cmd *cmd)
{
	char	*s;
	char	**envv;

	envv = put_in_tab();
	if (!cmd->next)
	{
		if (cmd->in == -1 || cmd->out == -1)
		{
			ft_free(envv);
			return ;
		}
		s = grant_access(cmd);
		if (!s)
		{
			ft_free(envv);
			return ;
		}
		fork_n_exec(cmd, s, envv);
		signal(SIGINT, handler);
		signal(SIGQUIT, handler);
		return ;
	}
	else
		pipe_it(cmd, envv);
	ft_free(envv);
}
