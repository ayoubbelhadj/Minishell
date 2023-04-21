/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 22:02:39 by aoudija           #+#    #+#             */
/*   Updated: 2023/04/21 04:52:30 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sigint_handler(int signum)
{
    rl_replace_line("", 0);
    putchar('\n');
	rl_on_new_line();
	rl_redisplay();
	signum++;
}

int	main()
{
	char	*cmd;
	char	**temp;
	char *args[2];
	int		pid;

	while(1)
	{
		signal(SIGINT, sigint_handler);
		cmd = readline("\x1B[34mmy_shell>\033[0m");
		temp = ft_split(cmd, ' ');
		if (cmd && temp[0])
		{
			// parse();
			// execute();
			if (!ft_strncmp(cmd, "env", 3))
			{
				pid = fork();
				if (pid == 0)
				{
					args[0] = "env";
					execv("/usr/bin/env", args);
					break ;
				}
			}
			else if (!ft_strncmp(cmd, "exit", 4))
				break;
			add_history(cmd);
		}
		free(cmd);
		ft_free(temp);
	}
	return 0;
}
