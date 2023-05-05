/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 12:15:49 by abelhadj          #+#    #+#             */
/*   Updated: 2023/05/05 16:43:55 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/minishell.h"

int	ft_start(char *line, t_data *data, t_cmd *cmd)
{
	if (check_syntax(line))
	{
		g_stuct.exit_status = SYNTAX_ERROR;
		printf("\033[0;31mSyntax Error!\n");
		return (0);
	}
	ft_tokenizer(line, &data);
	ft_get_cmd(&data, &cmd);
	ft_cmdclear(&cmd);
	ft_dataclear(&data);
	return (1);
}
