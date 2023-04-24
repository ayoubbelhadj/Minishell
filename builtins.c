/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 22:02:28 by aoudija           #+#    #+#             */
/*   Updated: 2023/04/24 07:31:12 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

void	ft_echo(char *cmd)
{
	size_t	len;
	char	*s;

	len = ft_strlen(cmd) - 5;
	s =  ft_substr(cmd, 5,len);
	printf("%s", s);
	free(s);
}

void	ft_env(void)
{
	int	i;

	i = -1;
	while (data->env[++i])
		printf("%s\n", data->env[i]);
}

void	ft_export(char *cmd)
{
	char	**temp;

	temp = ft_split(cmd, ' ');
	if (temp[1] && ft_str_not_in(data->env, temp[1]))
		data->env = twod_join(data->env, temp[1]);
	ft_free(temp);
}
