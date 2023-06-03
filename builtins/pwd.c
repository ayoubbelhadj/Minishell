/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 22:10:11 by aoudija           #+#    #+#             */
/*   Updated: 2023/05/28 20:25:22 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	pwd(t_cmd *cmd)
{
	char	cwd[PATH_MAX];

	getcwd(cwd, sizeof(cwd));
	ft_putstr_fd(cwd, cmd->out);
	write(cmd->out, "\n", 1);
	g_data.exit_status = 0;
}
