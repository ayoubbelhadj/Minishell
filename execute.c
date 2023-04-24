/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 23:52:49 by aoudija           #+#    #+#             */
/*   Updated: 2023/04/24 05:14:01 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

// void	put_in_tab(void)
// {
// 	t_list	*temp;
// 	int		size;
// 	int		i;

// 	size = ft_lstsize(data->cmd);
// 	data->cmd_tab = malloc(sizeof(char *) * size + 1);
// 	temp = data->cmd;
	// while (temp)
	// {
		// data.cmd_tab[i] = malloc(temp->size);
// 		data->cmd_tab[i] = temp->content;
// 		temp = data->cmd->next;
// 		i++;
// 	}
// 	data->cmd_tab[i] = 0;
// }

void	execute(char *cmd)
{
	// int	pid;
	int		i;
	char	**temp;

	if (!ft_strncmp(cmd, "echo", 5))
		ft_echo(cmd);
	else if (!ft_strncmp(cmd, "env", 3))
	{
		i = -1;
		while (data->env[++i])
			printf("%s\n", data->env[i]);
	}
	if (!ft_strncmp(cmd, "export", 6))
	{
		temp = ft_split(cmd, ' ');
		if (temp[1])
			data->env = twod_join(data->env, temp[1]);
	}
}
