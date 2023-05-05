/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:13:14 by aoudija           #+#    #+#             */
/*   Updated: 2023/05/05 16:29:31 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	**pathh(void)
{
	t_list	*temp;
	char	*t;
	char	**path;

	path = NULL;
	temp = g_data.env;
	while (temp)
	{
		t = ft_substr(temp->content, 0, 4);
		if (!ft_strcmp(t, "PATH"))
			path = ft_split(temp->content + 5, ':');
		free(t);
		temp = temp->next;
	}
	return (path);
}

char	**put_in_tab(void)
{
	t_list	*temp;
	int		i;
	char	**envv;

	temp = g_data.env;
	i = -1;
	envv = malloc(sizeof(char *) * ft_lstsize(temp) + 1);
	temp = g_data.env;
	while (temp)
	{
		envv[++i] = ft_strdup(temp->content);
		temp = temp->next;
	}
	envv[++i] = 0;
	return (envv);
}

void	pipe_it()
{
	// int		pipe_fd[2];
	int		pid;
	char	*s;
	char	*cmd_args[3] = {"ls", "-la", NULL};
	char	**path;
	char	**envv;
	int		a;
	int		i;

	a = 0;
	i = -1;
	path = pathh();
	while (path[++i])
	{
		s = ft_strjoin(path[i], "/ls");
		if (!access(s, F_OK))
		{
			a = 5;
			break ;
		}
		free(s);
	}
	if (a != 5)
		return ;
	envv = put_in_tab();
	pid = fork();
	if (!pid)
	{
		execve(s, cmd_args, envv);
		exit(0);
	}
	else
		waitpid(pid, NULL, 0);
	// int	fd_test = open("test.txt", O_RDWR);
	// s = malloc(strlen("hi from child\n"));
	// pipe(pipe_fd);
	// pid = fork();
	// if (!pid)
	// {
	// 	close(pipe_fd[0]);
	// 	write(pipe_fd[1], "hi from child\n", strlen("hi from child\n"));
	// 	close(pipe_fd[1]);
	// }
	// else if (pid)
	// {
	// 	close(pipe_fd[1]);
	// 	read(pipe_fd[0], s, strlen("hi from child\n"));
	// 	printf("->%s", s);
	// 	close(pipe_fd[0]);
	// }
}
