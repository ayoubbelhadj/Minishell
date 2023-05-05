/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 12:19:37 by abelhadj          #+#    #+#             */
/*   Updated: 2023/04/25 12:20:07 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_charjoin(char *s, char c)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(ft_strlen(s) + 2);
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i++] = c;
	str[i] = 0;
	free(s);
	return (str);
}
