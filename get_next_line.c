/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnarvaez <pnarvaez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 14:38:41 by pnarvaez          #+#    #+#             */
/*   Updated: 2026/06/23 13:02:01 by pnarvaez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*save_line(char **c)
{
	char			*line;
	char			*temp;
	unsigned int	pos;

	pos = 0;
	temp = ft_strdup(*c);
	if (!temp)
		return (NULL);
	while (temp[pos] && temp[pos] != '\n')
		pos++;
	if (temp[pos])
		pos++;
	line = ft_substr(*c, 0, pos);
	if (!line)
		return (free(temp), NULL);
	free(*c);
	*c = ft_substr(temp, pos, ft_strlen(temp));
	free(temp);
	if (!*c)
		return (free(line), NULL);
	if (!line[0])
		return (free(line), NULL);
	return (line);
}

static char	*read_line(int fd, char **c)
{
	char	*buff;
	char	*temp;
	int		bytes;

	buff = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes < 0)
			return (free(buff), NULL);
		buff[bytes] = '\0';
		temp = *c;
		*c = ft_strjoin(temp, buff);
		free(temp);
		if (!*c)
			return (free(buff), NULL);
		if (ft_strchr(*c, '\n') || bytes < BUFFER_SIZE)
			return (free(buff), save_line(c));
	}
	return (free(buff), NULL);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*c;

	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!c)
	{
		c = ft_strdup("");
		if (!c)
			return (NULL);
	}
	if (ft_strchr(c, '\n'))
	{
		line = save_line(&c);
		if (!line)
			return (free(c), c = NULL, NULL);
		return (line);
	}
	line = read_line(fd, &c);
	if (!line)
		return (free(c), c = NULL, NULL);
	return (line);
}
