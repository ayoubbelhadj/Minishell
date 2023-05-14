/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 17:22:47 by abelhadj          #+#    #+#             */
/*   Updated: 2023/05/13 20:05:15 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/minishell.h"

int	ft_heredocwrite(char *line, char *del, int fd, char *delimiter)
{
	line = readline("> ");
	if (!line)
		return (free(del), free(line), 1);
	if (line[0])
	{
		if (!ft_strcmp(line, del))
			return (free(del), free(line), 1);
		if (ft_isquotein(delimiter))
			line = ft_expand(line);
		ft_putstr_fd(line, fd);
		ft_putstr_fd("\n", fd);
	}
	free(line);
	return (0);
}

char	*ft_heredocfile(char *delimiter)
{
	char	*name;
	char	*del;
	int		fd;
	char	*line;

	name = ft_namegenerator();
	del = ft_expand_delimiter(delimiter);
	line = NULL;
	fd = open(name, O_TRUNC | O_CREAT | O_RDWR, 0777);
	while (1 && fd != -1)
	{
		if (ft_heredocwrite(line, del, fd, delimiter))
			break ;
	}
	close(fd);
	return (name);
}

int	ft_heredoc(t_token **data)
{
	t_token	*tmp;
	char	*filename;

	tmp = *data;
	signal(SIGINT, ft_heredocsig);
	while (tmp && !g_data.sig)
	{	
		if (tmp->type == HERDOC)
		{
			filename = ft_heredocfile(tmp->next->value);
			if (!filename)
				return (1);
			free(tmp->next->value);
			tmp->next->value = filename;
		}
		tmp = tmp->next;
	}
	if (g_data.sig)
		return (1);
	return (0);
}
