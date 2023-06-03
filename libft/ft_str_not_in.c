/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_not_in.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 07:14:21 by aoudija           #+#    #+#             */
/*   Updated: 2023/04/27 15:05:42 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_not_in(t_list *temp, char *arg)
{
	while (temp)
	{
		if (!ft_strcmp(temp->content, arg))
			return (0);
		temp = temp->next;
	}
	return (1);
}
