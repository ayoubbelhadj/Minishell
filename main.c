/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 22:02:39 by aoudija           #+#    #+#             */
/*   Updated: 2023/05/14 18:16:48 by abelhadj         ###   ########.fr       */
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
	ft_lstadd_back(&g_stuct.env, ft_lstnew("var=ls -l -a"));
}

void	ft_env0(void)
{
	t_list	*tmp;

	tmp = g_stuct.env;
	while (tmp)
	{
		printf("%s\n", tmp->content);
		tmp = tmp->next;
	}
}

void	handler(int sig)
{
	if (sig == SIGINT)
	{
		g_stuct.exit_status = 1;
		ft_putstr_fd("\n", 1);
		rl_replace_line("", 1);
		rl_on_new_line();
	}
	rl_on_new_line();
	rl_redisplay();
}

void	handle_signals(void)
{
	dup2(g_stuct.fstdin, 0);
	dup2(g_stuct.fstdout, 1);
	g_stuct.sig = 0;
	signal(SIGQUIT, handler);
	signal(SIGINT, handler);
}

int	main(int ac, char **av, char **env)
{
	t_token	*data;
	t_cmd	*cmd;
	char	*line;
	t_cmd	*tmp;
	int		i;

	ft_env(ac, av, env);
	data = malloc(sizeof(data));
	g_stuct.fstdin = dup(0);
	g_stuct.fstdout = dup(1);
	while (1)
	{
		handle_signals();
		line = readline("\033[1;36m bashn't$ \033[0m");
		if (!line)
			break ;
		if (line[0])
		{
			add_history(line);
			if (ft_start(line, data, &cmd))
			{
				tmp = cmd;
				while (tmp)
				{
					i = 0;
					printf("cmd: %s\n", tmp->cmd);
					printf("args: ");
					while (tmp->args && tmp->args[i])
					{
						printf("(%s) ", tmp->args[i]);
						i++;
					}
					printf("\n");
					tmp = tmp->next;
				}
				ft_cmdclear(&cmd);
			}
		}
		free(line);
	}
	return (0);
}
