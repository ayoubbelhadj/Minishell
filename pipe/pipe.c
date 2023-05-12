/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:13:14 by aoudija           #+#    #+#             */
/*   Updated: 2023/05/12 09:24:11 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	pipes(t_cmd *cmd, char **envv)
{
	int		pid;
	char	*s;
	int		**fd; /* fd[0] -> read && fd[1] -> write; */
	int		i;
	t_cmd	*tmp;

	tmp	= cmd;
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
		if (!i)/*first cmd*/
		{
			pipe(fd[i]);
			pid = fork();
			if (!pid)
			{
				dup2(cmd->in, 0);
				close(fd[i][0]);
				s = cmd_path(cmd);
				dup2(fd[i][1], cmd->out);
				close(fd[i][1]);
				execve(s, cmd->args, envv);
				exit(0);
			}
		}
		cmd = cmd->next;
		if (!cmd->next)/*last cmd*/
		{
			pid = fork();
			if (!pid)
			{
				dup2(cmd->in, 0);
				close(fd[i][1]);
				s = cmd_path(cmd);
				dup2(fd[i][0], cmd->in);
				dup2(cmd->out, 1);
				close(fd[i][0]);
				execve(s, cmd->args, envv);
				exit(0);
			}
		}
		else if (cmd->next)/*cmd-in-between*/
		{
			pipe(fd[++i]);
			pid = fork();
			if (!pid)
			{
				close(fd[i][0]);
				close(fd[i - 1][1]);
				s = cmd_path(cmd);
				dup2(fd[i - 1][0], cmd->in);
				dup2(fd[i][1], cmd->out);
				close(fd[i][1]);
				close(fd[i - 1][0]);
				execve(s, cmd->args, envv);
				exit(0);
			}
			else
				close(fd[i - 1][1]);
		}
	}
	i = cmd_list_size(tmp) - 2;
	while (i >= 0)
	{
		close(fd[i][0]);
		close(fd[i][1]);
		i--;
	}
	while (wait(NULL) > 0)
		;
	return ;
}

void	pipe_it(t_cmd *cmd)
{
	int		pid;
	char	*s;
	char	**envv;

	envv = put_in_tab();
	s = cmd_path(cmd);
	if (!cmd->next)
	{
		pid = fork();
		if (!pid)
		{
			dup2(cmd->in, 0);
			dup2(cmd->out, 1);
			execve(s, cmd->args, envv);
			exit(0);
		}
		else
		{
			waitpid(pid, NULL, 0);
			return ;
		}
	}
	pipes(cmd, envv);
}
