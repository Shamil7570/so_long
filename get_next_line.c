/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medeana <medeana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 14:25:29 by medeana           #+#    #+#             */
/*   Updated: 2021/12/14 13:24:26 by medeana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_remainder(char *remainder, char *line)
{
	int		i;
	int		j;
	int		len;

	len = ft_strlen(remainder);
	i = 0;
	while (remainder[i] && remainder[i] != '\n')
		i++;
	if (!remainder[i])
	{
		free(remainder);
		return (NULL);
	}
	line = (char *)malloc(sizeof(char) * len - i + 1);
	if (!line)
		return (NULL);
	i++;
	j = 0;
	while (remainder[i])
		line[j++] = remainder[i++];
	line[j] = '\0';
	free(remainder);
	return (line);
}

char	*read_file(int fd, char *remainder)
{
	char	*buff;
	int		read_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(remainder, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[read_bytes] = '\0';
		remainder = ft_strjoin(remainder, buff);
	}
	free(buff);
	return (remainder);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*remainder;
	int			i;

	line = NULL;
	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	remainder = read_file(fd, remainder);
	if (!remainder)
		return (NULL);
	if (*remainder)
	{
		while (remainder[i] && remainder[i] != '\n')
			i++;
		if (remainder[i] == '\n')
			i++;
		line = (char *)malloc(sizeof(char) * (i + 1));
		if (!line)
			return (NULL);
		ft_strcpy(line, remainder);
	}
	remainder = ft_remainder(remainder, line);
	return (line);
}
