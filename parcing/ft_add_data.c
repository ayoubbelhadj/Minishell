/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 12:23:25 by abelhadj          #+#    #+#             */
/*   Updated: 2023/04/27 13:20:39 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/minishell.h"

void	ft_add_operator(t_data **data, char *cmd, int *i)
{
	char	*str;

	str = ft_strdup("");
	while (cmd[*i] && ft_opt_check(cmd[*i], cmd, *i) && cmd[*i] != ' ')
	{
		str = ft_charjoin(str, cmd[*i]);
		if (!ft_strncmp(str, "<<", 2) || !ft_strncmp(str, ">>", 2)
			|| (!ft_strncmp(str, "<", 1) && cmd[*i + 1] != '<')
			|| (!ft_strncmp(str, ">", 1) && cmd[*i + 1] != '>')
			|| !ft_strncmp(str, "|", 1))
		{
			ft_data_addback(data, ft_datanew(str));
			break ;
		}
		(*i)++;
	}
}

void	ft_add_str(t_data **data, char *cmd, int *index)
{
	char	*str;
	int		i;

	i = *index;
	str = ft_strdup("");
	while (cmd[i] && !ft_opt_check(cmd[i], cmd, i))
	{
		str = ft_charjoin(str, cmd[i]);
		if ((cmd[i + 1] && ft_opt_check(cmd[i + 1], cmd, i)
				&& !quotes(cmd, i + 1)) || !cmd[i + 1]
			|| (cmd[i + 1] == ' ' && (!quotes(cmd, i + 1))))
		{
			ft_data_addback(data, ft_datanew(str));
			break ;
		}
		(i)++;
	}
	*index = i;
}
