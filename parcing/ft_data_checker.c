/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 12:18:34 by abelhadj          #+#    #+#             */
/*   Updated: 2023/05/05 16:33:54 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/minishell.h"

int	ft_check_herdoc(t_data **data)
{
	int		i;
	t_data	*tmp;

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
		printf("\033[0;31mmy_shell: maximum here-document count exceeded\n");
		return (1);
	}
	return (0);
}

int	ft_check_pipe(t_data **data)
{
	t_data	*tmp;

	tmp = *data;
	while (tmp)
	{
		if (tmp->type == PIPE)
		{
			if (!tmp->next || !tmp->prev)
			{
				printf("\033[0;31mmy_shell: syntax error" \
						" near unexpected token '|'\n");
				return (1);
			}
			else if (tmp->next && tmp->next->type == PIPE)
			{
				printf("\033[0;31mmy_shell: syntax error" \
					" near unexpected token '||'\n");
				return (1);
			}
		}
		tmp = tmp->next;
	}
	return (0);
}

int	ft_isopt(int type)
{
	if (type == OUTPUT || type == APPEND
		|| type == INPUT || type == HERDOC)
		return (1);
	return (0);
}

int	ft_check_opt(t_data **data)
{
	t_data	*tmp;

	tmp = *data;
	while (tmp)
	{
		if (ft_isopt(tmp->type) && !tmp->next)
		{
			printf("\033[0;31mmy_shell: syntax error near" \
				" unexpected token 'newline'\n");
			return (1);
		}
		if (ft_isopt(tmp->type) && tmp->next
			&& (ft_isopt(tmp->next->type) || tmp->next->type == PIPE))
		{
			printf("\033[0;31mmy_shell: syntax error near" \
				" unexpected token '%s'\n",
				tmp->next->value);
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

int	ft_check_data_syntax(t_data **data)
{
	if (ft_check_pipe(data))
		return (g_stuct.exit_status = ERROR, 1);
	if (ft_check_herdoc(data))
		return (g_stuct.exit_status = ERROR, 1);
	if (ft_check_opt(data))
		return (g_stuct.exit_status = ERROR_2, 1);
	return (0);
}
