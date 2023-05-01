/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 22:02:39 by aoudija           #+#    #+#             */
/*   Updated: 2023/04/29 15:53:56 by aoudija          ###   ########.fr       */
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

int	main(int ac, char **av, char **envv)
{
	char	*cmd;

	(void)ac;
	(void)av;

	fill_env(envv);
	fill_export();
	// exit (0);
	while (1)
	{
		signal(SIGINT, sigint_handler);
		cmd = readline("\x1B[34mmy_shell>\033[0m");
		if (cmd[0])
		{
			execute(cmd);
			if (!ft_strncmp(cmd, "exit", 4))
				break ;
			add_history(cmd);
			free(cmd);
		}
	}
	return (0);
}
