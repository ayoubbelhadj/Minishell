/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:35:11 by aoudija           #+#    #+#             */
/*   Updated: 2023/05/04 15:29:42 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

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
		{
			if (tenv->next)
			{
				tenv->content = tenv->next->content;
				tenv->next = tenv->next->next;
			}
			if (!tenv->next)
			{
				while (temp->next->next)
					temp = temp->next;
				temp->next = NULL;
			}
		}
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

void	ft_unset(char *cmd)
{
	char	**arg;

	arg = ft_split(cmd, ' ');
	if (!arg[1])
	{
		ft_free(arg);
		return ;
	}
	lenv(arg[1]);
	lexp(arg[1]);
}
