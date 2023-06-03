/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_fdeez.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:41:00 by aoudija           #+#    #+#             */
/*   Updated: 2023/05/30 13:51:20 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	close_fdeez(t_cmd *cmd, int **fd)
{
	int		i;

	i = cmd_list_size(cmd) - 2;
	while (i >= 0)
	{
		close(fd[i][0]);
		close(fd[i][1]);
		free(fd[i]);
		i--;
	}
	free(fd);
	waitpid(-1, &g_data.exit_status, 0);
	if (WIFSIGNALED(g_data.exit_status))
		g_data.exit_status += 128;
	else if (WIFEXITED(g_data.exit_status))
		g_data.exit_status = WEXITSTATUS(g_data.exit_status) % 255;
	while (wait(NULL) > 0)
		;
	signal(SIGINT, handler);
	signal(SIGQUIT, handler);
}
