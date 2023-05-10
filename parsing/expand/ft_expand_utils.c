/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 21:42:38 by abelhadj          #+#    #+#             */
/*   Updated: 2023/05/09 16:39:42 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/minishell.h"

char	*ft_dollarvalue(char *str)
{
	t_list	*tmp;
	int		len;
	char	*var;

	tmp = g_stuct.env;
	len = ft_strlen(str);
	while (tmp && str[0])
	{
		var = tmp->content;
		if (var[len] && !ft_strncmp(var, str, len) && var[len + 1]
			&& var[len] == '=')
			return (ft_strdup(var + len + 1));
		tmp = tmp->next;
	}
	return (ft_strdup(""));
}

char	*ft_getvalue(char *value, int *i)
{
	char	*s;
	char	*var;

	s = ft_strdup("");
	if (!ft_isalnum(value[*i + 1]) && value[*i + 1] != '_'
		&& value[(*i + 1)] != '?' && !ft_quotes(value, *i + 2))
	{
		while (value[*i] && value[*i] != '$')
			s = ft_charjoin(s, value[(*i)++]);
		if (value[*i] == '$')
			s = ft_charjoin(s, value[(*i)++]);
	}
	while (value[++(*i)] && (ft_isalnum(value[*i]) || value[*i] == '_'))
		s = ft_charjoin(s, value[*i]);
	(*i)--;
	var = ft_dollarvalue(s);
	free(s);
	return (var);
}

void	ft_getvarvalue(char *value, int *i, char **str, int	*flag)
{
	char	*v;

	*flag = 1;
	if (value[*i + 1] == '?')
	{
		(*i)++;
		v = ft_itoa(g_stuct.exit_status);
	}
	else
		v = ft_getvalue(value, i);
	*str = ft_strjoinfree(*str, v);
	free (v);
}

void	ft_getchar(char	*value, char **str, int i)
{
	if (value[i] != '\'' && value[i] != '\"')
		*str = ft_charjoin(*str, value[i]);
	if (value[i] == '\'' && ft_quotes(value, i) == 1)
		*str = ft_charjoin(*str, value[i]);
	if (value[i] == '\"' && ft_quotes(value, i) == 2)
		*str = ft_charjoin(*str, value[i]);
}