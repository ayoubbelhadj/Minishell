/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 12:27:55 by abelhadj          #+#    #+#             */
/*   Updated: 2023/05/05 16:33:11 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/minishell.h"

static int	ft_type_arg(t_data **data)
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

static void	ft_getchar(char	*value, char **str, int i)
{
	if (value[i] != '\'' && value[i] != '\"')
		*str = ft_charjoin(*str, value[i]);
	if (value[i] == '\'' && quotes(value, i) == 1)
		*str = ft_charjoin(*str, value[i]);
	if (value[i] == '\"' && quotes(value, i) == 2)
		*str = ft_charjoin(*str, value[i]);
}

void	ft_getvalue(char *value, int *i, char **str)
{
	char	*s;
	char	*v;

	s = *str;
	if (value[*i + 1] == '?')
	{
		(*i)++;
		v = ft_itoa(g_stuct.exit_status);
		s = ft_strjoinfree(*str, v);
		free(v);
	}
	*str = s;
}

static char	*ft_name_expand(char *value)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_strdup("");
	while (value[i])
	{
		if (value[i] == '$')
		{
			if (value[i + 1] != '$' && (!quotes(str, i) || quotes(str, i) == 1))
				ft_getvalue(value, &i, &str);
			else
				i++;
		}
		else
			ft_getchar(value, &str, i);
		i++;
	}
	free(value);
	return (str);
}

void	ft_cmd_type(t_data **data)
{
	t_data	*tmp;

	tmp = *data;
	while (tmp)
	{
		ft_type_arg(&tmp);
		if (tmp->type == INFILE || tmp->type == OUTFILE || tmp->type == APPOUT)
			tmp->value = ft_name_expand(tmp->value);
		tmp = tmp->next;
	}
}
