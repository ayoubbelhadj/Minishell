/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 22:02:28 by aoudija           #+#    #+#             */
/*   Updated: 2023/04/20 23:04:26 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

void	ft_echo(char *cmd)
{
	size_t	len;
	char	*s;

	len = ft_strlen(cmd) - 5;
	s =  ft_substr(cmd, 5,len);
	printf("%s", s);
	free(s);
}
