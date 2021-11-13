/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouta <asouta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 22:27:30 by asouta            #+#    #+#             */
/*   Updated: 2021/11/11 19:48:07 by asouta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*split(char **before, char c)
{
	char	*pos;
	char	*line;
	size_t	line_len;
	char	*temp;

	pos = ft_strchr(*before, c);
	line_len = pos - *before + 1;
	line = ft_substr(*before, 0, line_len);
	temp = *before;
	if (c == '\0')
		line_len -= 1;
	*before += line_len;
	*before = ft_substr(*before, 0, ft_strlen(*before));
	free(temp);
	if (line == NULL || *before == NULL)
	{
		free(before);
		free(line);
		before = NULL;
		line = NULL;
	}
	return (line);
}

static void	read_size(char **before, int fd)
{
	ssize_t	cnt;
	char	*temp;
	char	*buf;

	cnt = 1;
	while (cnt > 0 && ft_strchr(*before, '\n') == NULL)
	{
		buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE+1));
		if (buf == NULL)
			continue ;
		cnt = read(fd, buf, BUFFER_SIZE);
		if (cnt <= 0)
			free(buf);
		else
		{
			buf[cnt] = '\0';
			temp = *before;
			*before = ft_strjoin(*before, buf);
			free(temp);
			free(buf);
			if (*before == NULL)
				break ;
		}
	}
}

char	*get_next_line(int fd)
{
	static char		*before = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd == 1 || fd == 2 || 256 < fd)
		return (NULL);
	
	if (before == NULL)
	{
		before = ft_substr("", 1, 1);
		if (before == NULL)
		 	return (NULL);
	}
	read_size(&before, fd);
	if (ft_strchr(before, '\n'))
		return split(&before, '\n');
	else if (ft_strlen(before) > 0)
		return split(&before, '\0');
	free(before);
	before = NULL;
	return (NULL);
}
