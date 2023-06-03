/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_only.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:56:53 by aoudija           #+#    #+#             */
/*   Updated: 2023/05/29 16:27:50 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	export_only(t_cmd *cmd)
{
	t_list	*temp_exp;

	temp_exp = g_data.exp;
	if (!g_data.exp)
		return ;
	while (temp_exp)
	{
		ft_putstr_fd(temp_exp->content, cmd->out);
		write(cmd->out, "\n", 1);
		temp_exp = temp_exp->next;
	}
}
