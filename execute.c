/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 23:52:49 by aoudija           #+#    #+#             */
/*   Updated: 2023/05/01 12:49:41 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

void	execute(char *cmd)
{
	if (!strncmp("echo", cmd, 5))
		ft_echo(cmd);
	else if (!ft_strncmp("env", cmd, 5))
		ft_env();
	else if (!ft_strncmp("export", cmd, 6))
		ft_export(cmd);
	else if (!ft_strncmp("unset", cmd, 5))
		ft_unset(cmd);
	else if (!ft_strncmp("pwd", cmd, 3))
		printf("%s\n",getenv("PWD"));
	// else if (!ft_strncmp(cmd, "cd", 2))
	// 	ft_cd();
}
