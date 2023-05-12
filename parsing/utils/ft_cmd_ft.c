/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_ft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:43:32 by abelhadj          #+#    #+#             */
/*   Updated: 2023/05/11 14:40:52 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/minishell.h"

t_cmd	*ft_cmdlast(t_cmd *cmd)
{
	t_cmd	*temp;

	if (!cmd)
		return (NULL);
	temp = cmd;
	while (temp -> next != NULL)
	{	
		temp = temp -> next;
	}
	return (temp);
}

void	ft_cmdaddlist(t_cmd **cmd, t_cmd *new)
{
	t_cmd	*last;

	if (!cmd || !new)
		return ;
	if (!*cmd)
	{
		*cmd = new;
		return ;
	}
	last = ft_cmdlast(*cmd);
	last->next = new;
}

void	ft_cmddeloner(t_cmd *cmd)
{
	if (!cmd)
		return ;
	free(cmd->cmd);
	ft_freetab(cmd->args);
	free(cmd);
}

void	ft_cmdclear(t_cmd	**cmd)
{
	t_cmd	*temp;
	t_cmd	*t;

	if (!cmd)
		return ;
	t = *cmd;
	temp = *cmd;
	while (temp)
	{
		temp = t->next;
		ft_cmddeloner(t);
		t = temp;
	}
	*cmd = NULL;
}

int	ft_cmdsize(t_cmd *cmd)
{
	int	i;

	i = 0;
	while (cmd)
	{
		cmd = cmd->next;
		i++;
	}
	return (i);
}
