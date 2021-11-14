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

#include "get_next_line_bonus.h"

static char	*split(fd_lst *ptr, fd_lst *lst, char c)
{
	char	*pos;
	char	*line;
	size_t	line_len;
	char	*temp;

	pos = ft_strchr(ptr->before, c);
	line_len = pos - ptr->before + 1;
    line = ft_strdup(ptr->before, line_len);
	temp = ptr->before;
	if (c == '\0')
		line_len -= 1;
	ptr->before += line_len;
    ptr->before = ft_strdup(ptr->before, ft_strlen(ptr->before));
	free(temp);
	if (line == NULL || ptr->before == NULL)
	{
		ft_lstfree(&lst, ptr);
		free(line);
		//ptr->before = NULL;
		line = NULL;
	}
	return (line);
}

static void	read_size(fd_lst *ptr, int fd)
{
	ssize_t	cnt;
	char	*temp;
	char	*buf;

	cnt = 1;
	while (cnt > 0 && ft_strchr(ptr->before, '\n') == NULL)
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
			temp = ptr->before;
			ptr->before = ft_strjoin(ptr->before, buf);
			free(temp);
			free(buf);
			if (ptr->before == NULL)
				break ;
		}
	}
}

char	*get_next_line(int fd)
{
	static fd_lst	*lst = NULL;
    fd_lst          *ptr;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd == 1 || fd == 2 || 256 < fd)
		return (NULL);
	//printf("\nfd \t%d\n", fd);
	ptr = ft_lstadd(&lst, fd);
	read_size(ptr, fd);
	if (ft_strchr(ptr->before, '\n'))
		return split(ptr, lst, '\n');
	else if (ft_strlen(ptr->before) > 0)
		return split(ptr, lst, '\0');
	//printf("before ft_lstfree\n");
	ft_lstfree(&lst, ptr);
	return (NULL);
}