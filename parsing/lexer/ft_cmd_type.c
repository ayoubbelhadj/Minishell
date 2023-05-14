/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 12:27:55 by abelhadj          #+#    #+#             */
/*   Updated: 2023/05/14 18:44:19 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/minishell.h"

static int	ft_type_arg(t_token **data)
{
	if (ft_strcmp((*data)->value, "|") == 0)
		(*data)->type = PIPE;
	else if (ft_strcmp((*data)->value, ">>") == 0)
		(*data)->type = APPEND;
	else if (ft_strcmp((*data)->value, "<<") == 0)
		(*data)->type = HERDOC;
	else if (ft_strcmp((*data)->value, ">") == 0)
		(*data)->type = OUTPUT;
	else if (ft_strcmp((*data)->value, "<") == 0)
		(*data)->type = INPUT;
	else if ((*data)->prev && (*data)->prev->type == INPUT)
		(*data)->type = INFILE;
	else if ((*data)->prev && (*data)->prev->type == OUTPUT)
		(*data)->type = OUTFILE;
	else if ((*data)->prev && (*data)->prev->type == APPEND)
		(*data)->type = APPOUT;
	else if ((*data)->prev && (*data)->prev->type == HERDOC)
		(*data)->type = DELIMITER;
	else if (!(*data)->prev || (*data)->prev->type == PIPE)
		(*data)->type = CMD;
	else
		(*data)->type = ARG;
	return (1);
}

void	ft_cmd_type(t_token **data)
{
	t_token	*tmp;

	tmp = *data;
	while (tmp)
	{
		ft_type_arg(&tmp);
		if (tmp->type == APPOUT || tmp->type == OUTFILE
			|| tmp->type == INFILE)
			tmp->value = ft_expand_name(tmp->value);
		tmp = tmp->next;
	}
}
