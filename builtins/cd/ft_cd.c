/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 14:46:56 by aoudija           #+#    #+#             */
/*   Updated: 2023/05/14 22:06:34 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	found_var(char *var)
{
	t_list	*temp;
	int		i;

	i = 0;
	temp = g_data.env;
	while (temp)
	{
		if (!ft_strcmp(temp->content, var))
			i = 1;
		temp = temp->next;
	}
	return (i);
}

void	search_var(char *str, char *new)
{
	change_env(str, new);
	change_exp(str, new);
}

void	cd(t_cmd *cmd)
{
	int		i;
	char	cwd[1000];

	getcwd(cwd, sizeof(cwd));
	i = 0;
	if (cmd->args[1])
	{
		i = chdir(cmd->args[1]);
		norma_cd_1(cmd, cwd,i);
	}
	else if (!cmd->args[1])
		norma_cd_2(cwd);
}
