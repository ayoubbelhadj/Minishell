/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 14:55:07 by aoudija           #+#    #+#             */
/*   Updated: 2023/05/12 18:56:47 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	**put_in_tab(void)
{
	t_list	*temp;
	int		i;
	char	**envv;

	temp = g_data.env;
	i = -1;
	envv = malloc(sizeof(char *) * ft_lstsize(temp) + 1);
	temp = g_data.env;
	while (temp)
	{
		envv[++i] = ft_strdup(temp->content);
		temp = temp->next;
	}
	envv[++i] = 0;
	return (envv);
}

char	**path_env(void)
{
	t_list	*temp;
	char	*t;
	char	**path;

	path = NULL;
	temp = g_data.env;
	while (temp)
	{
		t = ft_substr(temp->content, 0, 4);
		if (!ft_strcmp(t, "PATH"))
			path = ft_split(temp->content + 5, ':');
		free(t);
		temp = temp->next;
	}
	return (path);
}

char	*cmd_path(t_cmd *cmd)
{
	char	*cmd_f;
	char	**path;
	char	*s;
	int		a;
	int		i;

	cmd_f = ft_strjoin("/", cmd->args[0]);
	a = 0;
	i = -1;
	path = path_env();
	while (path[++i])
	{
		s = ft_strjoin(path[i], cmd_f);
		if (!access(s, F_OK))
		{
			a = 5;
			break ;
		}
		free(s);
	}
	free(cmd_f);
	if (a != 5)
		return (NULL);
	return (s);
}
