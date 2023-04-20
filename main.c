/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 22:02:39 by aoudija           #+#    #+#             */
/*   Updated: 2023/04/20 23:47:11 by aoudija          ###   ########.fr       */
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

	data.i = 0;
	while(1)
	{
		signal(SIGINT, sigint_handler);
		cmd = readline("\x1B[34mmy_shell>\033[0m");
		temp = ft_split(cmd, ' ');
		if (cmd && temp[0])
		{
			if (!ft_strncmp(cmd, "exit", 4))
				break;
			add_history(cmd);
			if (!ft_strncmp(temp[0], "echo", 5))
				ft_echo(cmd);
		}
		free(cmd);
		ft_free(temp);
	}
	return 0;
}
