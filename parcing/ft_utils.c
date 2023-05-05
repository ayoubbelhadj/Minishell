/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 12:18:06 by abelhadj          #+#    #+#             */
/*   Updated: 2023/05/05 16:20:38 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/minishell.h"

int	check_syntax(char *cmd)
{
	int	i;
	int	checker;

	i = 0;
	checker = 0;
	while (cmd[i])
	{
		if (cmd[i] == '\"' && checker == 0)
			checker = 1;
		else if (cmd[i] == '\"' && checker == 1)
			checker = 0;
		else if (cmd[i] == '\'' && checker == 0)
		{
			while (cmd[i])
			{
				if (cmd[i] == '\'' && checker == 0)
					checker = 1;
				else if (cmd[i] == '\'' && checker == 1)
					checker = 0;
				i++;
			}
		}
		i++;
	}
	return (checker);
}

int	quotes(char *cmd, int index)
{
	int	i;
	int	checker;

	i = 0;
	checker = 0;
	while (cmd[i] && i != index)
	{
		if (checker == 0 && cmd[i] == '\"')
			checker = 1;
		else if (checker == 1 && cmd[i] == '\"')
			checker = 0;
		else if (checker == 0 && cmd[i] == '\'')
			checker = 2;
		else if (checker == 2 && cmd[i] == '\'')
			checker = 0;
		i++;
	}
	return (checker);
}

int	ft_opt_check(char c, char *cmd, int index)
{
	if (quotes(cmd, index))
		return (0);
	if (c && (c == '|' || c == '>' || c == ' ' || c == '<'))
		return (1);
	return (0);
}
