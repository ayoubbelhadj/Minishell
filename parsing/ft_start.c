/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 12:15:49 by abelhadj          #+#    #+#             */
/*   Updated: 2023/05/11 15:07:15 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/minishell.h"

int	ft_start(char *line, t_token *data, t_cmd **cmd)
{
	if (check_syntax(line))
	{
		g_data.exit_status = SYNTAX_ERROR;
		ft_putstr_fd("\033[0;31mSyntax Error!\n\033[0m", 2);
		return (0);
	}
	if (ft_tokenizer(line, &data))
		return (0);
	ft_get_cmd(&data, cmd);
	ft_dataclear(&data);
	return (1);
}
