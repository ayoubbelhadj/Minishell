/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:37:21 by abelhadj          #+#    #+#             */
/*   Updated: 2023/05/16 17:37:03 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/minishell.h"

void	ft_init_cmd(t_cmd *cmd)
{
	cmd->args = NULL;
	cmd->cmd = NULL;
	cmd->in = 0;
	cmd->out = 1;
	cmd->error = 1;
	cmd->next = NULL;
}

void	ft_cmdadd(t_cmd **cmd, t_cmd **new)
{
	ft_cmdaddlist(cmd, *new);
	*new = (t_cmd *)malloc(sizeof(t_cmd));
	ft_init_cmd(*new);
}

void	ft_cmd(char *value, t_cmd **cmd_tmp)
{
	(*cmd_tmp)->cmd = ft_strdup(value);
	if (ft_check_cmd((*cmd_tmp)->cmd))
			(*cmd_tmp)->in = -1;
}

void	ft_expand_check(t_token	*tmp, t_cmd *cmd_tmp)
{
	int		i;
	char	**ok;

	i = -1;
	if (tmp->type == CMD)
		ft_cmd(tmp->value, &cmd_tmp);
	if (tmp->flag && ft_strchr(tmp->value, ' '))
	{
		ok = ft_split(tmp->value, ' ');
		while (ok[++i])
			cmd_tmp->args = ft_realloc(cmd_tmp->args, ok[i]);
		ft_freetab(ok);
	}
	else
		cmd_tmp->args = ft_realloc(cmd_tmp->args, tmp->value);
}

void	ft_get_cmd(t_token **data, t_cmd **cmd)
{
	t_token	*tmp;
	t_cmd	*cmd_tmp;

	cmd_tmp = NULL;
	ft_cmdadd(cmd, &cmd_tmp);
	tmp = *data;
	if (ft_heredoc(data))
		return (ft_cmdclear(&cmd_tmp));
	while (tmp)
	{
		if (tmp->type == CMD || tmp->type == ARG)
			ft_expand_check(tmp, cmd_tmp);
		else if (tmp->type == APPEND || tmp->type == HERDOC
			|| tmp->type == INFILE || tmp->type == OUTFILE)
			ft_inoutfile(tmp, &cmd_tmp);
		if ((tmp->next && tmp->next->type == PIPE) || tmp->next == NULL)
			ft_cmdadd(cmd, &cmd_tmp);
		tmp = tmp->next;
	}
	free(cmd_tmp);
}
