/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 23:52:49 by aoudija           #+#    #+#             */
/*   Updated: 2023/05/12 15:12:37 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

void	execute(t_cmd	*cmd)
{
	
	// if (!ft_strncmp("echo", cmd->cmd, 4))
	// 	ft_echo(cmd->cmd);
	// else if (!ft_strncmp("env", cmd->cmd, 5))
	// 	ft_env();
	// else if (!ft_strncmp("export", cmd->cmd, 6))
	// 	ft_export(cmd->cmd);
	// else if (!ft_strncmp("unset", cmd->cmd, 5))
	// 	ft_unset(cmd->cmd);
	// else if (!ft_strncmp("pwd", cmd->cmd, 3))
	// 	printf("%s\n",getenv("PWD"));
	// else
		execute_it(cmd);
}
