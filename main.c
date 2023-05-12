/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 22:02:39 by aoudija           #+#    #+#             */
/*   Updated: 2023/05/11 14:30:45 by aoudija          ###   ########.fr       */
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
	char	*line;
	t_token	*data;
	t_cmd	*cmd;
	// t_cmd	*tmp;
	// int		i;

	(void)ac;
	(void)av;
	fill_env(envv);
	fill_export();
	data = malloc(sizeof(t_token *));
	cmd = NULL;
	while (1)
	{
		signal(SIGINT, sigint_handler);
		line = readline("\x1B[34mbashn't-2.0$ \033[0m");
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
	return (0);
}
