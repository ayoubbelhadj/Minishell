/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 22:02:39 by aoudija           #+#    #+#             */
/*   Updated: 2023/05/05 16:36:32 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

void	sigint_handler(int s)
{
	s = 0;
	ft_putstr_fd("\n", 1);
	rl_replace_line("", 1);
	rl_on_new_line();
	rl_redisplay();
}

void	ft_env(int ac, char **av, char **env)
{
	int	i;

	(void) ac;
	(void) av;
	i = 0;
	while (env[i])
		ft_lstadd_back(&g_stuct.env, ft_lstnew(env[i++]));
}

int	main(int ac, char **av, char **env)
{
	t_data	*data;
	t_cmd	*cmd;
	char	*line;

	cmd = NULL;
	ft_env(ac, av, env);
	signal(SIGQUIT, SIG_IGN);
	data = malloc(sizeof(data));
	while (1)
	{
		signal(SIGINT, sigint_handler);
		line = readline("\033[1;36m my_shell$ \033[0m");
		if (!line)
			break ;
		if (line[0])
		{
			add_history(line);
			ft_start(line, data, cmd);
		}
		free(line);
	}
	return (0);
}
