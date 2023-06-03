/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:47:48 by aoudija           #+#    #+#             */
/*   Updated: 2023/05/29 21:24:14 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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

int	normin(char *args, t_list *temp_exp, int plus)
{
	int		c;
	char	*t;

	t = ft_substr(args, 0, strlen_var(args));
	c = 0;
	if (ft_strchr(temp_exp->content, '=')
		&& !var_compare(temp_exp->content + 11, args))
	{
		if (plus)
			temp_exp->content = exp_plus(temp_exp->content, args);
		else
			temp_exp->content = exp_new_content(args);
		c = 1;
	}
	else if (!ft_strchr(temp_exp->content, '=')
		&& !ft_strcmp(temp_exp->content + 11, t))
	{
		temp_exp->content = exp_new_content(args);
		c = 1;
	}
	free(t);
	return (c);
}

int	exp_matching_vars(t_cmd *cmd, int i, int plus)
{
	t_list	*temp_exp;
	char	*t;
	int		c;

	temp_exp = g_data.exp;
	while (temp_exp)
	{
		t = temp_exp->content;
		c = normin(cmd->args[i], temp_exp, plus);
		if (c)
			free(t);
		temp_exp = temp_exp->next;
	}
	return (c);
}

int	env_new(t_cmd *cmd, int i, int plus)
{
	t_list	*temp_env;

	temp_env = g_data.env;
	while (temp_env)
	{
		if (!var_compare(temp_env->content, cmd->args[i]))
		{
			if (plus)
			{
				free(temp_env->content);
				temp_env->content = env_plus(temp_env->content, cmd->args[i]);
			}
			else
			{
				free(temp_env->content);
				temp_env->content = ft_strdup(cmd->args[i]);
			}
			return (0);
		}
		temp_env = temp_env->next;
	}
	return (1);
}

void	ft_export(t_cmd *cmd)
{
	t_list	*temp_exp;
	int		i;

	i = 0;
	temp_exp = g_data.exp;
	if (!cmd->args[1])
	{
		export_only(cmd);
		return ;
	}
	while (cmd->args[++i])
	{
		if (var_is_valid(cmd, cmd->args[i]))
		{
			if (!check(cmd, i))
			{
				if (ft_strchr(cmd->args[i], '='))
					export_norm1(cmd, i);
				else if (!ft_strchr(cmd->args[i], '='))
					export_norm2(cmd, i);
			}
		}
	}
	sort_exp();
}
