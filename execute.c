/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 23:52:49 by aoudija           #+#    #+#             */
/*   Updated: 2023/05/14 22:13:32 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

void	execute(t_cmd	*cmd)
{
	if (!cmd->cmd)
		return ;
	if (!ft_strcmp("echo", cmd->cmd))
		ft_echo(cmd);
	else if (!ft_strcmp("env", cmd->cmd))
		ft_env();
	else if (!ft_strcmp("export", cmd->cmd))
		ft_export(cmd);
	else if (!ft_strcmp("unset", cmd->cmd))
		ft_unset(cmd);
	else if (!ft_strcmp("cd", cmd->cmd))
		cd(cmd);
	else if (!ft_strcmp("pwd", cmd->cmd))
		pwd(cmd);
	else
		execute_it(cmd);
}
