/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 22:02:28 by aoudija           #+#    #+#             */
/*   Updated: 2023/05/01 13:01:44 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_echo(char *cmd)
{
	size_t	len;
	char	*s;

	len = ft_strlen(cmd) - 5;
	s = ft_substr(cmd, 5, len);
	printf("%s\n", s);
	free(s);
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

void	ft_export(char *cmd)
{
	char	**arg;
	t_list	*temp;
	int		c;

	c = 0;
	arg = ft_split(cmd, ' ');
	//cmd : export (only)
	if (!arg[1])
	{
		ft_free(arg);
		sort_exp();
		temp = g_data.exp;
		while (temp)
		{
			printf("%s\n", temp->content);
			temp = temp->next;
		}
		return ;
	}
	//cmd : export something=value
	temp = g_data.env;
	if (ft_strchr(arg[1], '=') && arg[1][ft_strlen(arg[1]) - 1] != '=')
	{
		while (temp)
		{
			if (ft_strchr(temp->content, '=') && !var_compare(temp->content, arg[1]))
			{
				temp->content = arg[1];
				c = 1;
			}
			temp = temp->next;
		}
		if (c == 0)
			ft_lstadd_back(&g_data.env, ft_lstnew(arg[1]));
	}
	else if (!ft_strchr(arg[1], '=') || arg[1][ft_strlen(arg[1]) - 1] == '=')
	{
		if (arg[1][ft_strlen(arg[1]) - 1] == '=')
		{
			
		}
		else
		{
				while (temp)
			{
				if (ft_strchr(temp->content, '=') && !var_compare(temp->content, arg[1]))
				{
					temp->content = ft_strjoin("declare -x ", arg[1]);
					c = 1;
				}
				temp = temp->next;
			}
			if (c == 0)
				ft_lstadd_back(&g_data.exp, ft_lstnew(ft_strjoin("declare -x ", arg[1])));
		}
	}
	sort_exp();
}

void	ft_unset(char *cmd)
{
	char	**arg;
	t_list	*temp;

	arg = ft_split(cmd, ' ');
	if (!arg[1])
	{
		ft_free(arg);
		return ;
	}
	temp = g_data.env;
	if (!ft_strchr(arg[1], '='))
	{
		while (temp)
		{
			if (!ft_strncmp(temp->content, arg[1], ft_strlen(arg[1]))
				&& ft_strlen(temp->content) >= ft_strlen(arg[1]))
			{
				temp->content = temp->next->content;
				free(temp->next);
				temp->next = temp->next->next;
			}
			temp = temp->next;
		}
		return ;
	}
	while (temp)
	{
		if (!strncmp(temp->content, arg[1], ft_strlen(arg[1]))
			&& ft_strlen(temp->content) == ft_strlen(arg[1]))
			temp->content = arg[1];
	}
	ft_free(arg);
}
