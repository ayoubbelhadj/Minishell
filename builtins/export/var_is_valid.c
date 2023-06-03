/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_is_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:00:18 by aoudija           #+#    #+#             */
/*   Updated: 2023/05/28 20:14:07 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	count_char(char *str, char c)
{
	int	i;
	int	ct;

	ct = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == c)
			ct++;
	}
	return (ct);
}

int	check_chars_unset(char *sub)
{
	int	i;

	i = -1;
	while (sub[++i])
	{
		if (!ft_isalnum(sub[i]) && sub[i] != '_')
			return (0);
	}
	return (1);
}

int	check_characters(char *sub, t_cmd *cmd)
{
	int	i;

	i = -1;
	if (!sub || ft_isdigit(sub[0]))
		return (0);
	if (!ft_strcmp("unset", cmd->cmd))
	{
		if (!check_chars_unset(sub))
			return (0);
		else
			return (1);
	}
	if (ft_strchr(sub, '+')
		&& (count_char(sub, '+') > 1 || sub[ft_strlen(sub) - 1] != '+'))
		return (0);
	else
	{
		while (sub[++i])
		{
			if (!ft_isalnum(sub[i]) && sub[i] != '_' && sub[i] != '+')
				return (0);
		}
	}
	return (1);
}

char	*substring(char *args)
{
	char	*sub;

	sub = NULL;
	if (strchr(args, '+') && args[ft_strlen(args) - 1] == '+'
		&& !ft_strchr(args, '='))
		sub = NULL;
	else
	{
		if (args[0] == '+' && args[ft_strlen(args) - 1] == '=')
			sub = NULL;
		else if (ft_strchr(args, '=') && strlen_var(args))
			sub = ft_substr(args, 0, strlen_var(args));
		else if (!ft_strchr(args, '='))
			sub = ft_strdup(args);
		if (!sub)
			sub = ft_strdup(args);
	}
	return (sub);
}

int	var_is_valid(t_cmd *cmd, char	*args)
{
	char	*j;
	char	*t;
	char	*sub;

	sub = substring(args);
	if (!check_characters(sub, cmd))
	{
		if (!sub)
			sub = ft_strdup(args);
		t = ft_strjoin("bashn't: ", cmd->cmd);
		j = ft_strjoin_frees1(t, ": ");
		t = ft_strjoin_frees1(j, sub);
		free(sub);
		j = ft_strjoin_frees1(t, ": not a valid identifier\n");
		ft_putstr_fd(j, 2);
		free(j);
		g_data.exit_status = 1;
		return (0);
	}
	free(sub);
	return (1);
}
