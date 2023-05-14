/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 17:39:52 by abelhadj          #+#    #+#             */
/*   Updated: 2023/05/13 20:05:15 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/minishell.h"

char	*ft_namegenerator(void)
{
	char	*name;
	char	*num;
	int		i;

	i = 0;
	num = ft_itoa(i);
	name = ft_strjoin("/tmp/herdoc_", num);
	free(num);
	while (!access(name, F_OK))
	{
		free(name);
		num = ft_itoa(i++);
		name = ft_strjoin("/tmp/herdoc_", num);
		free(num);
	}
	return (name);
}

char	*ft_expand_delimiter(char *delimiter)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_strdup("");
	while (delimiter[i])
	{
		ft_getchar(delimiter, &str, i);
		i++;
	}
	return (str);
}

void	ft_heredocsig(int sig)
{
	if (sig == SIGINT)
	{
		g_data.sig = 1;
		rl_replace_line("", 0);
		printf("\n");
		close(0);
	}
}
