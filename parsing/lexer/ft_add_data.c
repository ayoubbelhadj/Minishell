/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 12:23:25 by abelhadj          #+#    #+#             */
/*   Updated: 2023/05/09 18:21:32 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/minishell.h"

void	ft_add_operator(t_token **data, char *cmd, int *i)
{
	char	*str;

	str = ft_strdup("");
	while (cmd[*i] && ft_red_check(cmd[*i], cmd, *i) && cmd[*i] != ' ')
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

int	is_red(char c)
{
	if (c && (c == '|' || c == '>' || c == ' ' || c == '<'))
		return (1);
	return (0);
}

void	ft_add_str(t_token **data, char *cmd, int *index)
{
	char	*str;
	int		i;

	i = *index;
	str = ft_strdup("");
	while (cmd[i] && !ft_red_check(cmd[i], cmd, i))
	{
		str = ft_charjoin(str, cmd[i]);
		if ((cmd[i + 1] && is_red(cmd[i + 1])
				&& !ft_quotes(cmd, i + 1)) || !cmd[i + 1]
			|| (cmd[i + 1] == ' ' && (!ft_quotes(cmd, i + 1))))
		{
			ft_data_addback(data, ft_datanew(str));
			break ;
		}
		(i)++;
	}
	*index = i;
}
