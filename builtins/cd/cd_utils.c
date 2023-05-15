/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 21:12:55 by aoudija           #+#    #+#             */
/*   Updated: 2023/05/14 22:07:53 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	change_env(char *str, char *new)
{
	t_list	*temp;
	char	*sub;
	char	*s;

	temp = g_data.env;
	while (temp)
	{
		sub = ft_substr(temp->content, 0, ft_strlen(str));
		if (!ft_strcmp(sub, str))
		{
			s = ft_strjoin(str, "=");
			s = ft_strjoin_frees1(s, new);
			temp->content = s;
		}
		free(sub);
		temp = temp->next;
	}
}

void	change_exp(char *str, char *new)
{
	t_list	*temp;
	char	*sub;
	char	*s;

	temp = g_data.exp;
	while (temp)
	{
		sub = ft_substr(temp->content + 11, 0, ft_strlen(str));
		if (!ft_strcmp(sub, str))
		{
			s = ft_strjoin(str, "=");
			s = ft_strjoin_frees1(s, new);
			temp->content = exp_new_content(s);
			free(s);
		}
		free(sub);
		temp = temp->next;
	}
}

void	norma_cd_1(t_cmd *cmd, char *cwd, int i)
{
	char	*err;
	char	new[1024];

	if (i)
	{
		err = ft_strjoin("bashn't: ", cmd->args[0]);
		err = ft_strjoin_frees1(err, ": ");
		err = ft_strjoin_frees1(err, cmd->args[1]);
		perror(err);
		free(err);
	}
	else
	{
		search_var("OLDPWD", cwd);
		getcwd(new, sizeof(new));
		search_var("PWD", new);
	}
}

void	norma_cd_2(char *cwd)
{
	char	*err;
	char	new[1024];

	if (found_var("HOME=/Users/aoudija"))
	{
		chdir("/Users/aoudija");
		search_var("OLDPWD", cwd);
		getcwd(new, sizeof(new));
		search_var("PWD", new);
	}
	else
	{
		err = ft_strdup("bashn't: cd: HOME not set\n");
		ft_putstr_fd(err, 2);
		free(err);
	}
}
