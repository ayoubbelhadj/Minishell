/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 16:52:50 by aoudija           #+#    #+#             */
/*   Updated: 2023/05/30 17:58:37 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*exp_plus(char *exp_old, char *exp_new)
{
	char	*sub;
	char	*new;

	sub = ft_substr(exp_old, 0, ft_strlen(exp_old) - 1);
	new = ft_strjoin_frees1(sub, exp_new + strlen_var(exp_new) + 1);
	new = ft_strjoin_frees1(new, "\"");
	return (new);
}

char	*env_plus(char *env_old, char *env_new)
{
	char	*sub;
	char	*new;

	sub = ft_substr(env_old, 0, ft_strlen(env_old));
	new = ft_strjoin_frees1(sub, env_new + strlen_var(env_new) + 1);
	return (new);
}

void	export_norm1(t_cmd *cmd, int i)
{
	int	c;
	int	plus;

	plus = 0;
	if (ft_strchr(cmd->args[i], '+'))
	{
		cmd->args[i] = remove_char(cmd->args[i], '+');
		plus = 1;
	}
	c = 0;
	if (g_data.exp->content)
		c = exp_matching_vars(cmd, i, plus);
	if (env_new(cmd, i, plus))
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
	if (g_data.exp->content)
	{
		while (temp_exp)
		{
			t = ft_substr(temp_exp->content + 11, 0,
					strlen_var(temp_exp->content + 11));
			if (next && !ft_strcmp(t, cmd->args[i]))
				next = 0;
			temp_exp = temp_exp->next;
			free(t);
		}
	}
	if (next)
		ft_lstadd_back(&g_data.exp,
			ft_lstnew(ft_strjoin("declare -x ", cmd->args[i])));
}

char	*remove_char(char *str, char c)
{
	int		i;

	i = -1;
	while (str[++i] != '=' && str[i])
	{
		if (str[i] == c)
		{
			while (str[i + 1])
			{
				str[i] = str[i + 1];
				i++;
			}
			str[i] = 0;
		}
	}
	return (str);
}
