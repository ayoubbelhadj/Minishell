/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exexute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 23:52:49 by aoudija           #+#    #+#             */
/*   Updated: 2023/04/21 06:09:40 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	put_in_tab(void)
// {
// 	t_list	*temp;
// 	int		size;
// 	int		i;

// 	size = ft_lstsize(data->cmd);
// 	data->cmd_tab = malloc(sizeof(char *) * size + 1);
// 	temp = data->cmd;
	// while (temp)
	// {
		// data.cmd_tab[i] = malloc(temp->size);
// 		data->cmd_tab[i] = temp->content;
// 		temp = data->cmd->next;
// 		i++;
// 	}
// 	data->cmd_tab[i] = 0;
// }

// void	execute(void)
// {
// 	int	pid;

// 	if (!ft_strncmp(data->cmd_tab[0], "echo", 5))
// 		ft_echo(data->cmd_tab[1]);
// 	else if (!ft_strncmp(data->cmd_tab[0], "env", 3))
// 	{
// 		pid = fork();
// 		if (pid == 0)
// 		{
// 			args[0] = "env";
// 			execv("/usr/bin/env", args);
// 		}
// 	}
// }
