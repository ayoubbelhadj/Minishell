/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdupdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 06:52:01 by aoudija           #+#    #+#             */
/*   Updated: 2023/04/24 13:18:03 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strdupdup(char **tab)
{
	int		i;
	char	**new;

	i = -1;
	while (tab[++i])
		;
	new = ft_calloc(sizeof(char *), i + 1);
	i = -1;
	while (tab[++i])
		new[i] = ft_strdup(tab[i]);
	return (new);
}
