/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 17:39:52 by abelhadj          #+#    #+#             */
/*   Updated: 2023/05/30 20:39:15 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/minishell.h"

char	*ft_namegenerator(void)
{
	char	*heredocname;
	char	*num;
	int		i;

	i = 0;
	num = ft_itoa(i);
	heredocname = ft_strjoin("/tmp/hd_", num);
	free(num);
	while (!access(heredocname, F_OK))
	{
		free(heredocname);
		num = ft_itoa(i++);
		heredocname = ft_strjoin("/tmp/hd_", num);
		free(num);
	}
	return (heredocname);
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
		g_data.exit_status = 1;
		g_data.sig = 1;
		g_data.sigflag = 1;
		rl_replace_line("", 0);
		printf("\n");
		close(0);
	}
}
