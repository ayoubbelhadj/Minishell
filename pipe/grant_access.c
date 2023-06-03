/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grant_access.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:54:22 by aoudija           #+#    #+#             */
/*   Updated: 2023/05/29 22:11:04 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*normyyy(t_cmd *cmd)
{
	char	*s;

	if (!ft_strchr(cmd->args[0], '/'))
		s = cmd_path(cmd);
	else
		s = ft_strdup(cmd->args[0]);
	return (s);
}

char	*grant_access(t_cmd *cmd)
{
	char	*s;
	char	*err;

	s = normyyy(cmd);
	if (access(s, F_OK | X_OK) == -1)
	{
		if (errno == 14)
		{
			err = ft_strjoin("bashn't: ", cmd->args[0]);
			err = ft_strjoin_frees1(err, ": command not found\n");
			ft_putstr_fd(err, 2);
			g_data.exit_status = CMD_NOT_FOUND;
			free(err);
			return (NULL);
		}
		else
		{
			err = ft_strjoin("bashn't: ", cmd->args[0]);
			g_data.exit_status = 1;
			perror(err);
			return (free(err), free(s), NULL);
		}
	}
	return (s);
}
