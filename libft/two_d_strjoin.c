/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_d_strjoin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 00:18:23 by aoudija           #+#    #+#             */
/*   Updated: 2023/04/24 13:17:43 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**twod_join(char **tab, char *str)
{
	int		i;
	char	**new;
	int		j;

	i = -1;
	while (tab[++i])
		;
	new = malloc (sizeof(char *) * (i + 2));
	if (!new)
		return (NULL);
	i = -1;
	while (tab[++i])
		new[i] = ft_strdup(tab[i]);
	j = ft_strlen(str);
	new[i] = ft_strdup(str);
	ft_free(tab);
	return (new);
}
