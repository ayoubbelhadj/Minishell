/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 22:02:28 by aoudija           #+#    #+#             */
/*   Updated: 2023/05/05 17:27:22 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_echo(char *cmd)
{
	printf("%s", cmd + 5);
}

void	ft_env(void)
{
	t_list	*temp;

	temp = g_data.env;
	while (temp)
	{
		printf("%s\n", temp->content);
		temp = temp->next;
	}
}
