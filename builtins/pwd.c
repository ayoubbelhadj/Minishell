/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 22:10:11 by aoudija           #+#    #+#             */
/*   Updated: 2023/05/14 22:15:29 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	pwd(t_cmd *cmd)
{
	char	cwd[1000];

	getcwd(cwd, sizeof(cwd));
	ft_putstr_fd(cwd, cmd->out);
	write(cmd->out, "\n", 1);
}
