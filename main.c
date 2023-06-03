/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 22:02:39 by aoudija           #+#    #+#             */
/*   Updated: 2023/05/30 15:53:25 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

void	execute(t_cmd	*cmd)
{
	if (!cmd || (!cmd->args && !cmd->next))
		return ;
	if (cmd_list_size(cmd) == 1 && is_builtin(cmd))
	{
		if (!ft_strcmp("echo", cmd->args[0]) && !cmd->next
			&& cmd->error)
			ft_echo(cmd);
		else if (!ft_strcmp("env", cmd->args[0]) && !cmd->next)
			ft_env(cmd);
		else if (!ft_strcmp("exit", cmd->args[0]) && !cmd->next)
			ft_exit(cmd);
		else if (!ft_strcmp("export", cmd->args[0]) && !cmd->next)
			ft_export(cmd);
		else if (!ft_strcmp("unset", cmd->args[0]) && !cmd->next)
			ft_unset(cmd);
		else if (!ft_strcmp("cd", cmd->args[0]) && !cmd->next)
			cd(cmd);
		else if (!ft_strcmp("pwd", cmd->args[0]) && !cmd->next)
			pwd(cmd);
	}
	else
		execute_it(cmd);
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
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, handler);
}

void	cz_norma_is_a_karen(t_token *data, t_cmd *cmd)
{
	char	*line;

	while (1)
	{
		handle_signals();
		line = readline("bashn't-3.3$ ");
		g_data.sigflag = 0;
		if (!line)
		{
			printf("exit\n");
			break ;
		}
		if (line[0])
		{
			add_history(line);
			if (ft_start(line, data, &cmd))
			{
				execute(cmd);
				ft_cmdclear(&cmd);
			}
		}
		free(line);
	}
}

int	main(int ac, char **av, char **envv)
{
	t_token	*data;
	t_cmd	*cmd;

	if (ac == 1)
	{
		g_data.fstdin = dup(0);
		g_data.fstdout = dup(1);
		(void)av;
		fill_env(envv);
		fill_export();
		data = malloc(sizeof(t_token *));
		cmd = NULL;
		cz_norma_is_a_karen(data, cmd);
		free(data);
	}
	exit(g_data.exit_status);
}
