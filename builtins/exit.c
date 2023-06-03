/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:52:46 by aoudija           #+#    #+#             */
/*   Updated: 2023/05/26 09:36:36 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	all_digit(char *args)
{
	int	i;

	i = -1;
	while (args[++i])
	{
		if (!ft_isdigit(args[i]))
			return (0);
	}
	return (1);
}

int	norm(t_cmd *cmd)
{
	int		i;
	char	*j;

	i = 0;
	if (!all_digit(cmd->args[1]))
	{
		j = ft_strjoin("bashn't: exit: ", cmd->args[1]);
		j = ft_strjoin_frees1(j, ": numeric argument required\n");
		ft_putstr_fd(j, 2);
		free(j);
		g_data.exit_status = 255;
	}
	else if (all_digit(cmd->args[1]) && cmd->args[2])
	{
		ft_putstr_fd("bash: exit: too many arguments\n", 2);
		g_data.exit_status = 255;
		i = 1;
	}
	else if (all_digit(cmd->args[1]) && !cmd->args[2])
		g_data.exit_status = ft_atoi(cmd->args[1]);
	return (i);
}

void	ft_exit(t_cmd *cmd)
{
	int		i;

	i = 0;
	g_data.exit_status = 0;
	write(cmd->out, "exit\n", 5);
	if (cmd->args[1])
		i = norm(cmd);
	if (!i)
		exit(g_data.exit_status);
}
