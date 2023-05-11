/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenizer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 12:16:57 by abelhadj          #+#    #+#             */
/*   Updated: 2023/05/11 14:35:25 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/minishell.h"

int	ft_tokenizer(char *cmd, t_token **data)
{
	int	i;

	i = -1;
	*data = NULL;
	while (cmd[++i])
	{
		if (cmd[i] && !ft_red_check(cmd[i], cmd, i))
			ft_add_str(data, cmd, &i);
		if (cmd[i] && ft_red_check(cmd[i], cmd, i) && cmd[i] != ' ')
			ft_add_operator(data, cmd, &i);
	}
	ft_cmd_type(data);
	if (ft_check_data_syntax(data))
		return (ft_dataclear(data), 1);
	return (0);
}
