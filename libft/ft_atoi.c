/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 20:08:24 by abelhadj          #+#    #+#             */
/*   Updated: 2023/04/21 09:34:06 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<limits.h>

int	ft_atoi(const char *nptr)
{
	int			sign;
	long long	nbr;
	long long	n;
	long long	i;

	i = 0;
	sign = 1;
	nbr = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
		if (nptr[i++] == '-')
			sign *= -1;
	while (ft_isdigit(nptr[i]))
	{
		n = nbr;
		nbr = nbr * 10 + (nptr[i++] - '0');
		if (n != nbr / 10 && sign == 1)
			return (-1);
		else if (n != nbr / 10 && sign == -1)
			return (0);
	}
	return (nbr * sign);
}
