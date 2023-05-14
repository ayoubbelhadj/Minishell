/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 12:18:34 by abelhadj          #+#    #+#             */
/*   Updated: 2023/05/13 20:05:15 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/minishell.h"

int	ft_check_herdoc(t_token **data)
{
	int		i;
	t_token	*tmp;

	tmp = *data;
	i = 0;
	while (tmp)
	{
		if (tmp->type == HERDOC)
			i++;
		tmp = tmp->next;
	}
	if (i > 16)
	{
		ft_putstr_fd("bashn't: maximum here-document count"
			" exceeded\n", 2);
		return (1);
	}
	return (0);
}

int	ft_check_pipe(t_token **data)
{
	t_token	*tmp;

	tmp = *data;
	while (tmp)
	{
		if (tmp->type == PIPE)
		{
			if (!tmp->next || !tmp->prev)
			{
				ft_putstr_fd("bashn't: syntax error" \
						" near unexpected token '|'\n", 2);
				return (1);
			}
			else if (tmp->next && tmp->next->type == PIPE)
			{
				ft_putstr_fd("bashn't: syntax error" \
					" near unexpected token '||'\n", 2);
				return (1);
			}
		}
		tmp = tmp->next;
	}
	return (0);
}

int	ft_isred(int type)
{
	if (type == OUTPUT || type == APPEND
		|| type == INPUT || type == HERDOC)
		return (1);
	return (0);
}

int	ft_check_red(t_token **data)
{
	t_token	*tmp;

	tmp = *data;
	while (tmp)
	{
		if (ft_isred(tmp->type) && !tmp->next)
		{
			ft_putstr_fd("bashn't: syntax error near" \
				" unexpected token 'newline'\n", 2);
			return (1);
		}
		if (ft_isred(tmp->type) && tmp->next
			&& (ft_isred(tmp->next->type) || tmp->next->type == PIPE))
		{
			ft_putstr_fd("bashn't: syntax error near" \
				" unexpected token '", 2);
			ft_putstr_fd(tmp->next->value, 2);
			ft_putstr_fd("'\n", 2);
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

int	ft_check_data_syntax(t_token **data)
{
	if (ft_check_pipe(data))
		return (g_data.exit_status = ERROR, 1);
	if (ft_check_herdoc(data))
		return (g_data.exit_status = ERROR, 1);
	if (ft_check_red(data))
		return (g_data.exit_status = ERROR_2, 1);
	return (0);
}
