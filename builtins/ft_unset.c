/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:35:11 by aoudija           #+#    #+#             */
/*   Updated: 2023/05/14 14:13:49 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	shut_up_norma(t_list **tenv, t_list **temp)
{
	if ((*tenv)->next)
	{
		(*tenv)->content = (*tenv)->next->content;
		(*tenv)->next = (*tenv)->next->next;
	}
	if (!(*tenv)->next)
	{
		while ((*temp)->next->next)
			(*temp) = (*temp)->next;
		(*temp)->next = NULL;
	}
}

void	lenv(char	*arg)
{
	t_list	*tenv;
	t_list	*temp;
	char	*t;

	temp = g_data.env;
	tenv = g_data.env;
	while (tenv)
	{
		t = ft_substr(tenv->content, 0, strlen_var(tenv->content));
		if (!ft_strcmp(t, arg))
			shut_up_norma(&tenv, &temp);
		free(t);
		tenv = tenv->next;
	}
}

void	lexp(char *arg)
{
	t_list	*texp;
	t_list	*temp;
	char	*t;

	temp = g_data.exp;
	texp = g_data.exp;
	while (texp)
	{
		t = ft_substr(texp->content + 11, 0, strlen_var(texp->content + 11));
		if (!ft_strcmp(t, arg))
		{
			if (texp->next)
			{
				texp->content = texp->next->content;
				texp->next = texp->next->next;
			}
			if (!texp->next)
			{
				while (temp->next->next)
					temp = temp->next;
				temp->next = NULL;
			}
		}
		free(t);
		texp = texp->next;
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
			lenv(cmd->args[i]);
			lexp(cmd->args[i]);
		}
	}
}
