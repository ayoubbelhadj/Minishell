/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:37:21 by abelhadj          #+#    #+#             */
/*   Updated: 2023/05/05 16:38:28 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/minishell.h"

void	ft_init_cmd(t_cmd *cmd)
{
	cmd->args = NULL;
	cmd->red_args = NULL;
	cmd->cmd = NULL;
	cmd->next = NULL;
}

void	ft_cmdadd(t_cmd **cmd, t_cmd **new)
{
	ft_cmdaddlist(cmd, *new);
	*new = (t_cmd *)malloc(sizeof(t_cmd));
	ft_init_cmd(*new);
}

void	ft_get_cmd(t_data **data, t_cmd **cmd)
{
	t_data	*tmp;
	t_cmd	*cmd_tmp;

	cmd_tmp = NULL;
	ft_cmdadd(cmd, &cmd_tmp);
	tmp = *data;
	while (tmp)
	{
		if (tmp->type == CMD)
			cmd_tmp->cmd = tmp->value;
		if (tmp->type == CMD || tmp->type == ARG)
			cmd_tmp->args = ft_realloc(cmd_tmp->args, tmp->value);
		else if (tmp->type == APPEND || tmp->type == HERDOC
			|| tmp->type == OUTPUT || tmp->type == INPUT)
		{
			cmd_tmp->red_args = ft_realloc(cmd_tmp->red_args, tmp->value);
			cmd_tmp->red_args = ft_realloc(cmd_tmp->red_args, tmp->next->value);
		}
		if ((tmp->next && tmp->next->type == PIPE) || tmp->next == NULL)
			ft_cmdadd(cmd, &cmd_tmp);
		tmp = tmp->next;
	}
	free(cmd_tmp);
}
