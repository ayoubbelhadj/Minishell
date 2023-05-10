/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 14:25:33 by abelhadj          #+#    #+#             */
/*   Updated: 2023/05/05 14:43:08 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_realloc(char **tab, char *str)
{
	char	**t;
	int		i;

	i = 0;
	while (tab && tab[i])
		i++;
	t = malloc(sizeof(char *) * (i + 2));
	i = 0;
	while (tab && tab[i])
	{
		t[i] = ft_calloc(sizeof(char), 1);
		t[i] = ft_strjoinfree(t[i], tab[i]);
		i++;
	}
	t[i] = ft_calloc(sizeof(char), 1);
	t[i] = ft_strjoinfree(t[i], str);
	i++;
	t[i] = NULL;
	ft_freetab(tab);
	return (t);
}
