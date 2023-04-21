/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:14:39 by abelhadj          #+#    #+#             */
/*   Updated: 2023/04/20 22:06:18 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static char	*lastline(char *str)
{
	size_t	len;
	size_t	i;
	size_t	j;
	char	*line;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	while (str && str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	len = ft_strlen_get(&str[i++ + 1]);
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	while (str && str[i])
		line[j++] = str[i++];
	line[j] = '\0';
	free(str);
	return (line);
}

static char	*getreadline(char *str)
{
	char	*line;
	int		i;

	i = 0;
	if (!str[0])
		return (NULL);
	while (str && str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		line = malloc(i + 2);
	else
		line = malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (str && str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*readline(int fd, char *buff)
{
	char	*str;
	ssize_t	i;

	if (BUFFER_SIZE == 2147483647)
		str = malloc(BUFFER_SIZE);
	else
		str = malloc(BUFFER_SIZE + 1);
	if (!str)
		return (NULL);
	i = 1;
	while (!ft_strchr_get(buff, '\n') && i != 0)
	{
		i = read(fd, str, BUFFER_SIZE);
		if (i == -1)
		{
			free(str);
			return (NULL);
		}
		str[i] = '\0';
		buff = ft_strjoin_get(buff, str);
	}
	free(str);
	return (buff);
}

char	*get_next_line(int fd)
{
	static char	*myline;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > 2147483647)
		return (NULL);
	myline = readline(fd, myline);
	if (!myline)
		return (NULL);
	line = getreadline(myline);
	myline = lastline(myline);
	return (line);
}
