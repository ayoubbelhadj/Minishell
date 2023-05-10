/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_name.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:52:48 by abelhadj          #+#    #+#             */
/*   Updated: 2023/05/09 16:39:33 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/minishell.h"

int	ft_isquotein(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
			return (0);
		i++;
	}
	return (1);
}

int	ft_isspace_in(char *str)
{
	int	i;
	int	c;
	int	flag;

	i = 0;
	flag = 0;
	c = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if ((str[i] != '\t' && str[i] != ' ') && flag == 0)
		{
			flag = 1;
			c++;
		}
		if ((str[i] == '\t' || str[i] == ' '))
			flag = 0;
		i++;
	}
	return (c);
}

char	*ft_expand_name(char *value)
{
	char	*str;
	int		flag;
	int		i;

	i = 0;
	flag = 0;
	str = ft_strdup("");
	while (value[i])
	{
		if (value[i] == '$' && ft_ischard(value[i + 1])
			&& (ft_quotes(value, i) == 0 || ft_quotes(value, i) == 1))
		{
			if (value[i + 1] != '$' && !ft_isdigit(value[i + 1]))
				ft_getvarvalue(value, &i, &str, &flag);
			else
				i++;
		}
		else
			ft_getchar(value, &str, i);
		i++;
	}
	if (flag && (!str[0] || ft_isspace_in(str) > 1))
		return (free(value), free(str), ft_strdup("\b"));
	return (free(value), str);
}
