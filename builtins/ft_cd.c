/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 14:46:56 by aoudija           #+#    #+#             */
/*   Updated: 2023/05/14 18:22:18 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	search_var(char *str, char *new)
{
	t_list	*temp;
	char	*sub;

	temp = g_data.env;
	while (temp)
	{
		sub = ft_substr(temp->content, 0, ft_strlen(str));
		if (!ft_strcmp(temp->content, str))
			temp->content = ft_strdup(new);
		temp = temp->next;
	}
}

void	cd(t_cmd *cmd)
{
	int	i;

	i = 0;
	if (cmd->args[1])
	{
		i = chdir(cmd->args[1]);
		if (i)
			perror("");
		else
		{
			/*search and replace*/
		}
	}
}
