/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 22:02:39 by aoudija           #+#    #+#             */
/*   Updated: 2023/04/21 06:22:52 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

void	sigint_handler(int signum)
{
	signum++;
	// data.i = 1;
}

int	check_syntax(char *cmd)
{
	int	i;
	int	checker;

	i = 0;
	checker = 0;
	while (cmd[i])
	{
		if (cmd[i] == '\"' && checker == 0)
			checker = 1;
		else if (cmd[i] == '\"' && checker == 1)
			checker = 0;
		else if (cmd[i] == '\'' && checker == 0)
		{
			while (cmd[i])
			{
				if (cmd[i] == '\'' && checker == 0)
					checker = 1;
				else if (cmd[i] == '\'' && checker == 1)
					checker = 0;
				i++;
			}
		}
		i++;
	}
	return (checker);
}

int	main(void)
{
	char	*cmd;

	while (1)
	{
		signal(SIGINT, sigint_handler);
		cmd = readline("\033[1;36m my_shell$ \033[0m");
		if (cmd && cmd[0])
		{
			add_history(cmd);
			if (check_syntax(cmd))
			{
				printf("Syntax Error!\n");
				add_history(cmd);
				free(cmd);
				continue ;
			}
			if (!ft_strncmp(cmd, "exit", 4))
				break ;
		}
		free(cmd);
	}
	return (0);
}
