/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 22:02:39 by aoudija           #+#    #+#             */
/*   Updated: 2023/04/18 06:05:55 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sigint_handler(int signum)
{
	signum++;
	rl_redisplay();
	// data.i = 1;
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
		// rl_redisplay();
		// printf("$%s$\n", cmd);
		// if (data.i == 1)
		// {
		// 	// printf("%d", data.i);
		// 	rl_redisplay();
		// 	// data.i = -1;
		// 	// cmd = ft_strdup("");
		// 	// printf("/$%s$", cmd);
		// }
		temp = ft_split(cmd, ' ');
		if (cmd && temp[0])
		{
			if (!ft_strncmp(cmd, "exit", 4))
				break;
			add_history(cmd);
			if (!ft_strncmp(temp[0], "echo", 5))
				ft_echo(cmd);
		}
		// if (data.i == -1)
			free(cmd);
		ft_free(temp);
	}
	return 0;
}
