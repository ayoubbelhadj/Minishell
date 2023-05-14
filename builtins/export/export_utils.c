/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 16:52:50 by aoudija           #+#    #+#             */
/*   Updated: 2023/05/14 12:23:18 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	export_norm1(t_cmd *cmd, int i)
{
	int	c;

	c = 0;
	c = exp_matching_vars(cmd, i);
	if (env_new_exp(cmd, i, c))
	{
		ft_lstadd_back(&g_data.env, ft_lstnew(ft_strdup(cmd->args[i])));
		if (!c)
			ft_lstadd_back(&g_data.exp,
				ft_lstnew(exp_new_content(cmd->args[i])));
	}
}

void	export_norm2(t_cmd *cmd, int i)
{
	t_list	*temp_exp;
	int		next;
	char	*t;

	next = 1;
	temp_exp = g_data.exp;
	while (temp_exp)
	{
		t = ft_substr(temp_exp->content + 11, 0,
				strlen_var(temp_exp->content + 11));
		if (next && !ft_strcmp(t, cmd->args[i]))
			next = 0;
		temp_exp = temp_exp->next;
		free(t);
	}
	if (next)
		ft_lstadd_back(&g_data.exp,
			ft_lstnew(ft_strjoin("declare -x ", cmd->args[i])));
}

int	check_characters(char *sub)
{
	int	i;

	i = -1;
	if (ft_isdigit(sub[0]))
		return (0);
	else
	{
		while (sub[++i])
		{
			if (!ft_isalnum(sub[i]) && sub[i] != '_')
				return (0);
		}
	}
	return (1);
}

int	var_is_valid(t_cmd *cmd, char	*args)
{
	char	*j;
	char	*t;
	char	*sub;

	sub = NULL;
	if (ft_strchr(args, '=') && strlen_var(args))
		sub = ft_substr(args, 0, strlen_var(args));
	else if (!ft_strchr(args, '='))
		sub = ft_strdup(args);
	if (!sub)
		sub = ft_strdup(args);
	if (!check_characters(sub))
	{
		t = ft_strjoin("bashn't: ", cmd->cmd);
		j = ft_strjoin_frees1(t, ": ");
		t = ft_strjoin_frees1(j, sub);
		free(sub);
		j = ft_strjoin_frees1(t, ": not a valid identifier\n");
		ft_putstr_fd(j, cmd->out);
		free(j);
		return (0);
	}
	return (1);
}
