/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:23:23 by aoudija           #+#    #+#             */
/*   Updated: 2023/05/05 17:27:22 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	fill_env(char **envv)
{
	int	i;

	i = -1;
	while (envv[++i])
		ft_lstadd_back(&g_data.env, ft_lstnew(envv[i]));
}
