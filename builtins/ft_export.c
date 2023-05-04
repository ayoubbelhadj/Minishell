/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:47:48 by aoudija           #+#    #+#             */
/*   Updated: 2023/05/03 10:51:38 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*exp_new_content(char *arg)
{
	char	*t;
	char	*d;
	char	*sub;

	d = ft_strdup("declare -x ");
	sub = ft_substr(arg, 0, strlen_var(arg) + 1);
	t = ft_strjoin(d, sub);
	free(sub);
	free(d);
	d = ft_strjoin(t, "\"");
	free(t);
	t = ft_strjoin(d, arg + (strlen_var(arg) + 1));
	free(d);
	d = ft_strjoin(t, "\"");
	free(t);
	return (d);
}

void	ft_export(char *cmd)
{
	t_list	*temp_exp;
	t_list	*temp_env;
	char	**arg;
	char	*t;
	int		c;

	c = 0;
	arg = ft_split(cmd, ' ');
	temp_exp = g_data.exp;
	if (!arg[1])
	{
		while (temp_exp)
		{
			printf("%s\n", temp_exp->content);
			temp_exp = temp_exp->next;
		}
		return ;
	}
	temp_exp = g_data.exp;
	temp_env = g_data.env;
	if (ft_strchr(arg[1], '='))
	{
		while (temp_exp)
		{
			if (ft_strchr(temp_exp->content, '=')
				&& !var_compare(temp_exp->content + 11, arg[1]))//there is a match
			{
				temp_exp->content = exp_new_content(arg[1]);
				c = 1;
			}
			else if (!ft_strchr(temp_exp->content, '=')//there is a match but like this var && var=x
				&& !ft_strcmp(temp_exp->content + 11,
				ft_substr(arg[1], 0, strlen_var(arg[1]))))
			{
				temp_exp->content = exp_new_content(arg[1]);
				c = 1;
			}	
			temp_exp = temp_exp->next;
		}
		while (temp_env)
		{
			if (!ft_strcmp(temp_env->content, arg[1]))
			{
				if (!c)
					ft_lstadd_back(&g_data.exp, ft_lstnew(ft_strjoin("declare -x ", arg[1])));
				return ;
			}
			if (ft_strchr(temp_env->content, '=') && !var_compare(temp_env->content, arg[1]))
			{
				temp_env->content = arg[1];
				if (!c)
					ft_lstadd_back(&g_data.exp, ft_lstnew(ft_strjoin("declare -x ", arg[1])));
				return ;
			}
			temp_env = temp_env->next;
		}
		temp_exp = g_data.exp;
		ft_lstadd_back(&g_data.env, ft_lstnew(arg[1]));
		if (!c)
			ft_lstadd_back(&g_data.exp, ft_lstnew(exp_new_content(arg[1])));
	}
	else if (!ft_strchr(arg[1], '='))//case no '='
	{
		while (temp_exp)
		{
			t = ft_substr(temp_exp->content + 11, 0, strlen_var(temp_exp->content + 11));
			if (!ft_strcmp(t, arg[1]))//there is a match
			{
				free(t);
				return ;
			}
			temp_exp = temp_exp->next;
			free(t);
		}
		// t = ft_strjoin("declare -x ", arg[1]);
		ft_lstadd_back(&g_data.exp, ft_lstnew(ft_strjoin("declare -x ", arg[1])));//no match nex var (without '=')
		// free(t);
	}
	sort_exp();
}

