/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_checker2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 17:38:14 by abelhadj          #+#    #+#             */
/*   Updated: 2023/05/09 16:46:04 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/minishell.h"

int	ft_isdir(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '/')
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_cmd(char *str)
{
	DIR		*dr;

	if (str && ft_isdir(str))
	{
		if (!str[1])
		{
			(ft_putstr_fd("\033[0;31mmy_shell: ", 2), ft_putstr_fd(str, 2));
			ft_putstr_fd(" :is a directory\033[0;0m\n", 2);
			return (g_stuct.exit_status = CMD_NOT_EXECUT, 1);
		}
		else
		{
			dr = opendir(str);
			if (dr)
			{
				(ft_putstr_fd("\033[0;31mmy_shell: ", 2), ft_putstr_fd(str, 2));
				ft_putstr_fd(" :is a directory\033[0;0m\n", 2);
				if (dr)
					closedir(dr);
				return (g_stuct.exit_status = CMD_NOT_EXECUT, 1);
			}
		}
	}
	return (0);
}
