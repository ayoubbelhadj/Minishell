/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 14:46:56 by aoudija           #+#    #+#             */
/*   Updated: 2023/05/30 15:29:45 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*found_var(char *var)
{
	t_list	*temp;
	int		i;
	char	*t;

	i = 0;
	temp = g_data.env;
	while (temp)
	{
		t = ft_substr(temp->content, 0,
				strlen_var(temp->content));
		if (!ft_strcmp(t, var))
		{
			free(t);
			return (temp->content + ft_strlen(var) + 1);
		}
		free(t);
		temp = temp->next;
	}
	return (NULL);
}

void	search_var(char *str, char *new)
{
	change_env(str, new);
	change_exp(str, new);
}

void	cd(t_cmd *cmd)
{
	int		i;
	char	cwd[PATH_MAX];

	getcwd(cwd, sizeof(cwd));
	i = 0;
	if (cmd->args[1])
	{
		i = chdir(cmd->args[1]);
		norma_cd_1(cmd, cwd, i);
	}
	else if (!cmd->args[1])
		norma_cd_2(cwd);
}
