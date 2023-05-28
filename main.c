/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 22:02:39 by aoudija           #+#    #+#             */
/*   Updated: 2023/05/28 20:51:02 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

void	ft_envv(char **env)
{
	int	i;

	i = 0;
	while (env[i])
		ft_lstadd_back(&g_data.env, ft_lstnew(env[i++]));
	ft_lstadd_back(&g_data.env, ft_lstnew("var=ls -l -a"));
}

void	handler(int sig)
{
	if (sig == SIGINT)
	{
		g_data.exit_status = 1;
		if (!g_data.sigflag)
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

void	cz_norma_is_a_karen(t_token *data, t_cmd *cmd)
{
	char	*line;
	t_cmd	*tmp;
	int		i;

	while (1)
	{
		handle_signals();
		line = readline("bashn't-3.3$ ");
		g_data.sigflag = 0;
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
}

int	main(int ac, char **av, char **env)
{
	t_token	*data;
	t_cmd	*cmd;

	if (ac == 1)
	{
		g_data.fstdin = dup(0);
		g_data.fstdout = dup(1);
		(void)av;
		ft_envv(env);
		data = malloc(sizeof(t_token *));
		cmd = NULL;
		cz_norma_is_a_karen(data, cmd);
		free(data);
	}
	return (0);
}
