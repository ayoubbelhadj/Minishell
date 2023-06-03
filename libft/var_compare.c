/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_compare.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:45:06 by aoudija           #+#    #+#             */
/*   Updated: 2023/05/03 10:39:34 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	var_compare(char *content, char *arg)
{
	int	i;

	i = 0;
	while (content[i] != '=' || arg[i] != '=')
	{
		if (content[i] != arg[i])
			break ;
		i++;
	}
	return (content[i] - arg[i]);
}
