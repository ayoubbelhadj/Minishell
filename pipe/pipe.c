/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:13:14 by aoudija           #+#    #+#             */
/*   Updated: 2023/05/14 08:33:16 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	pipe_it(t_cmd *cmd, char **envv)
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
			if (cmd->in != -1 || cmd->out != -1)
			{
				pipe(fd[i]);
				pid = fork();
				if (!pid)
				{
					s = grant_access(cmd);
					if (!s)
						exit(EXIT_FAILURE);
					dup2(cmd->in, 0);
					dup2(cmd->out, 1);
					close(fd[i][0]);
					dup2(fd[i][1], cmd->out);
					close(fd[i][1]);
					if (cmd->out != -1)
						execve(s, cmd->args, envv);
					exit(EXIT_FAILURE);
				}
			}
		}
		cmd = cmd->next;
		if (!cmd->next)/*last cmd*/
		{
			if (!cmd->args)
				return ;
			if (cmd->in != -1)
			{
				pid = fork();
				if (!pid)
				{
					s = grant_access(cmd);
					if (!s)
						exit(EXIT_FAILURE);
					dup2(cmd->in, 0);
					close(fd[i][1]);
					dup2(fd[i][0], cmd->in);
					dup2(cmd->out, 1);
					close(fd[i][0]);
					if (cmd->out != -1)
						execve(s, cmd->args, envv);
					exit(EXIT_FAILURE);
				}
			}
		}
		else if (cmd->next)/*cmd-in-between*/
		{
			if (cmd->in != -1 || cmd->out != -1)
			{
				pipe(fd[++i]);
				pid = fork();
				if (!pid)
				{
					s = grant_access(cmd);
					if (!s)
						exit(EXIT_FAILURE);
					dup2(cmd->out, 1);
					close(fd[i][0]);
					close(fd[i - 1][1]);
					dup2(fd[i - 1][0], cmd->in);
					dup2(fd[i][1], cmd->out);
					close(fd[i][1]);
					close(fd[i - 1][0]);
					if (cmd->out != -1)
						execve(s, cmd->args, envv);
					exit(EXIT_FAILURE);
				}
				else
					close(fd[i - 1][1]);
			}
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

void	execute_it(t_cmd *cmd)
{
	int		pid;
	char	*s;
	char	**envv;
	int		status;

	envv = put_in_tab();
	if (!cmd->next)
	{
		if (cmd->in == -1 || cmd->out == -1)
			return ;
		if (!cmd->args)
			return ;
		s = grant_access(cmd);
		if (!s)
			return ;
		pid = fork();
		if (!pid)
		{
			dup2(cmd->in, 0);
			dup2(cmd->out, 1);
			execve(s, cmd->args, envv);
			free(s);
			perror("");
			exit(EXIT_FAILURE);
		}
		else
		{
			waitpid(pid, &status, 0);
			free(s);
			ft_free(envv);
			return ;
		}
	}
	pipe_it(cmd, envv);
	ft_free(envv);
}
