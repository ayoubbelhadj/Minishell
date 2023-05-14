/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 22:02:39 by aoudija           #+#    #+#             */
/*   Updated: 2023/05/14 18:30:27 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

void	sigint_handler(int signum)
{
	rl_replace_line("", 0);
	putchar('\n');
	rl_on_new_line();
	rl_redisplay();
	signum++;
}

void	handler(int sig)
{
	if (sig == SIGINT)
	{
		g_data.exit_status = 1;
		ft_putstr_fd("\n", 1);
		rl_replace_line("", 1);
		rl_on_new_line();
	}
	rl_on_new_line();
	rl_redisplay();
}

void	handle_signals(void)
{
	dup2(g_data.fstdin, 0);
	dup2(g_data.fstdout, 1);
	g_data.sig = 0;
	signal(SIGQUIT, handler);
	signal(SIGINT, handler);
}

int	main(int ac, char **av, char **envv)
{
	char	*line;
	t_token	*data;
	t_cmd	*cmd;

	// i = 0;
	// t_cmd	*tmp;
	// int		i;
	if (ac == 1)
	{
		g_data.fstdin = dup(0);
		g_data.fstdout = dup(1);
		(void)av;
		fill_env(envv);
		fill_export();
		data = malloc(sizeof(t_token *));
		cmd = NULL;
		while (1)
		{
			handle_signals();
			line = readline("\x1B[34mmy_shell$ \033[0m");
			if (line[0])
			{
				if (!ft_strcmp(line, "exit"))
					break ;
				add_history(line);
				if(ft_start(line, data, &cmd))
				{
					execute(cmd);
					ft_cmdclear(&cmd);
				}
			}
			free(line);
		}
		free(data);
	}
	return (0);
}
