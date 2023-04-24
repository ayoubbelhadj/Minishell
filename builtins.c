/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 22:02:28 by aoudija           #+#    #+#             */
/*   Updated: 2023/04/24 13:25:33 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

void	ft_echo(char *cmd)
{
	size_t	len;
	char	*s;

	len = ft_strlen(cmd) - 5;
	s = ft_substr(cmd, 5, len);
	printf("%s", s);
	free(s);
}

void	ft_env(void)
{
	int	i;

	i = -1;
	while (g_data->env[++i])
		printf("%s\n", g_data->env[i]);
}

void	ft_export(char *cmd)
{
	char	**temp;

	temp = ft_split(cmd, ' ');
	if (temp[1] && ft_str_not_in(g_data->env, temp[1]))
		g_data->env = twod_join(g_data->env, temp[1]);
	ft_free(temp);
}

void	ft_unset(char *cmd)
{
	int		i;
	int		j;
	int		pos;
	char	**temp;

	temp = ft_split(cmd, ' ');
	i = -1;
	pos = 0;
	while (g_data->env[++i])
	{
		j = -1;
		while (g_data->env[i][++j])
		{
			if (g_data->env[i][j] == '='
				&& !ft_strncmp(g_data->env[i], temp[1], j))
				pos = j;
		}
		if (pos)
			break ;
	}
	free(g_data->env[i]);
	g_data->env[i] = ft_strdup(temp[1]);
	ft_free(temp);
}
