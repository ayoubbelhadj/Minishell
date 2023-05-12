/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grant_access.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:54:22 by aoudija           #+#    #+#             */
/*   Updated: 2023/05/12 19:49:09 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*grant_access(t_cmd *cmd)
{
	char	*s;
	char	*err;

	if (!ft_strchr(cmd->args[0], '/'))
		s = cmd_path(cmd);
	else
		s = ft_strdup(cmd->args[0]);
	if (access(s, F_OK) == -1)
	{
		if (errno == 14)
		{
			err = ft_strjoin("bash: ", cmd->args[0]);
			err = ft_strjoin_frees1(err, ": command not found");
			printf("%s\n", err);
			free(err);
			return (NULL);
		}
		else
		{
			err = ft_strjoin("bash: ", cmd->args[0]);
			perror(err);
			free(err);
			free(s);
			return (NULL);
		}
	}
	else if (!access(s, F_OK))
		return (NULL);
	return (s);
}
