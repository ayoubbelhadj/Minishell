/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 08:34:02 by aoudija           #+#    #+#             */
/*   Updated: 2023/05/24 11:06:36 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	is_builtin(t_cmd *cmd)
{
	if (!cmd->args)
		return (0);
	if (!ft_strcmp("echo", cmd->args[0]))
		return (1);
	else if (!ft_strcmp("env", cmd->args[0]))
		return (1);
	else if (!ft_strcmp("export", cmd->args[0]))
		return (1);
	else if (!ft_strcmp("unset", cmd->args[0]))
		return (1);
	else if (!ft_strcmp("cd", cmd->args[0]))
		return (1);
	else if (!ft_strcmp("pwd", cmd->args[0]))
		return (1);
	else if (!ft_strcmp("exit", cmd->args[0]))
		return (1);
	return (0);
}

void	exec_builtin(t_cmd *cmd)
{
	if (!ft_strcmp("echo", cmd->args[0]))
		ft_echo(cmd);
	else if (!ft_strcmp("env", cmd->args[0]))
		ft_env(cmd);
	else if (!ft_strcmp("export", cmd->args[0]))
		ft_export(cmd);
	else if (!ft_strcmp("unset", cmd->args[0]))
		ft_unset(cmd);
	else if (!ft_strcmp("cd", cmd->args[0]))
		cd(cmd);
	else if (!ft_strcmp("pwd", cmd->args[0]))
		pwd(cmd);
	else if (!ft_strcmp("exit", cmd->args[0]))
		ft_exit(cmd);
}
