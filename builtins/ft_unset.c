/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:35:11 by aoudija           #+#    #+#             */
/*   Updated: 2023/05/29 20:34:20 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	delete(t_list **head, char *content, int x)
{
	t_list	*current;
	t_list	*prev;
	char	*t;

	current = *head;
	prev = NULL;
	while (current)
	{
		t = ft_substr(current->content + x, 0,
				strlen_var(current->content + x));
		if (!ft_strcmp(t, content))
		{
			if (prev == NULL)
				*head = current->next;
			else
				prev->next = current->next;
			free(current->content);
			current->content = NULL;
			return (free(current), free(t));
		}
		(free(t), prev = current, current = current->next);
	}
}

void	ft_unset(t_cmd *cmd)
{
	int	i;

	i = 0;
	if (!cmd->args[1])
		return ;
	while (cmd->args[++i])
	{
		if (var_is_valid(cmd, cmd->args[i]))
		{
			delete(&g_data.env, cmd->args[i], 0);
			delete(&g_data.exp, cmd->args[i], 11);
		}
	}
}
