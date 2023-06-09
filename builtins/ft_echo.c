/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 22:02:28 by aoudija           #+#    #+#             */
/*   Updated: 2023/05/30 15:50:12 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	n_or_not(char	**args, int i)
{
	size_t	j;

	j = 1;
	while (args[i][++j] == 'n' && args[i][j])
		;
	return (j == ft_strlen(args[i]));
	return (i);
}

void	ft_echo(t_cmd *cmd)
{
	int		i;
	int		j;

	i = 0;
	j = 1;
	while (cmd->args[++i] && cmd->args[i][0] == '-' && cmd->args[i][1] == 'n'
		&& n_or_not(cmd->args, i))
		j = 0;
	i--;
	if (j == 0)
	{
		while (cmd->args[++i])
			write(cmd->out, cmd->args[i], ft_strlen(cmd->args[i]));
	}
	else
	{
		while (cmd->args[++i])
		{
			write(cmd->out, cmd->args[i], ft_strlen(cmd->args[i]));
			if (cmd->args[i + 1])
				write(cmd->out, " ", 1);
		}
		write(cmd->out, "\n", 1);
	}
	g_data.exit_status = 0;
}
