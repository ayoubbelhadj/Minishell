/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 12:15:49 by abelhadj          #+#    #+#             */
/*   Updated: 2023/05/13 20:05:15 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/minishell.h"

int	ft_checkquote(char *line)
{
	char	*c;

	if (check_syntax(line))
	{
		if (check_syntax(line) == 1)
			c = "\"\n";
		else
			c = "'\n";
		g_data.exit_status = SYNTAX_ERROR;
		ft_putstr_fd("bashn't: syntax error near unexpected token ", 2);
		ft_putstr_fd(c, 2);
		return (1);
	}
	return (0);
}

int	ft_start(char *line, t_token *data, t_cmd **cmd)
{
	if (ft_checkquote(line))
		return (0);
	if (ft_tokenizer(line, &data))
		return (0);
	ft_get_cmd(&data, cmd);
	ft_dataclear(&data);
	if (g_data.sig == 1)
		return (0);
	return (1);
}
