/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exexute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 23:52:49 by aoudija           #+#    #+#             */
/*   Updated: 2023/04/21 01:05:22 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	put_in_tab(void)
{
	t_list	*temp;
	int		size;
	int		i;

	size = ft_lstsize(cmd);
	data.cmd_tab = malloc(sizeof(char *) * size + 1);
	temp = cmd;
	while (temp)
	{
		// data.cmd_tab[i] = malloc(temp->size);
		data.cmd_tab[i] = temp->content;
		temp = cmd->next;
		i++;
	}
	data.cmd_tab[i] = 0;
}

void	execute(t_list *cmd)
{
	
}
