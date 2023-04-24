/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 23:52:49 by aoudija           #+#    #+#             */
/*   Updated: 2023/04/24 07:28:52 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

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

void	execute(char *cmd)
{
	if (!ft_strncmp(cmd, "echo", 5))
		ft_echo(cmd);
	else if (!ft_strncmp(cmd, "env", 3))
		ft_env();
	if (!ft_strncmp(cmd, "export", 6))
		ft_export(cmd);
}
