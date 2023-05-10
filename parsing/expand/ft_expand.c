/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:52:48 by abelhadj          #+#    #+#             */
/*   Updated: 2023/05/09 16:39:48 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/minishell.h"

char	*ft_expand(char *value)
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
	return (free(value), str);
}
