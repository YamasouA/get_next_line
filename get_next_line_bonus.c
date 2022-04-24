/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouta <asouta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 22:27:30 by asouta            #+#    #+#             */
/*   Updated: 2022/04/21 21:29:27 by asouta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_lstfree(t_fd_lst **lst, t_fd_lst *target)
{
	t_fd_lst	*temp;

	if (*lst == target)
	{
		*lst = target->next;
		free(target->before);
		free(target);
		return ;
	}
	temp = *lst;
	while (temp->next != target)
		temp = temp->next;
	temp->next = target->next;
	free(target->before);
	free(target);
}

t_fd_lst	*ft_lstadd(t_fd_lst **lst, int fd)
{
	t_fd_lst	*new;

	new = *lst;
	while (new != NULL && new->fd != fd)
		new = new->next;
	if (new == NULL)
	{
		new = (t_fd_lst *)malloc(sizeof(t_fd_lst));
		if (!new)
			return (NULL);
		new->fd = fd;
		new->before = ft_strdup("", 0);
		if (new->before == NULL)
		{
			free(new);
			return (NULL);
		}
		new->next = *lst;
		*lst = new;
	}
	return (new);
}

static char	*split(t_fd_lst *ptr, t_fd_lst *lst, char c)
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
	ptr->before = ft_strdup(ptr->before + line_len, ft_strlen(ptr->before));
	free(temp);
	if (line == NULL || ptr->before == NULL)
	{
		ft_lstfree(&lst, ptr);
		free(line);
		line = NULL;
	}
	return (line);
}

static void	read_size(t_fd_lst *ptr, int fd)
{
	ssize_t	cnt;
	char	*temp;
	char	*buf;

	cnt = 1;
	while (cnt > 0 && ft_strchr(ptr->before, '\n') == NULL)
	{
		buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
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
	static t_fd_lst	*lst = NULL;
	t_fd_lst		*ptr;

	if (fd < 0 || BUFFER_SIZE <= 0 || 256 < fd)
		return (NULL);
	ptr = ft_lstadd(&lst, fd);
	if (ptr == NULL)
		return (NULL);
	read_size(ptr, fd);
	if (ft_strchr(ptr->before, '\n'))
		return (split(ptr, lst, '\n'));
	else if (ft_strlen(ptr->before) > 0)
		return (split(ptr, lst, '\0'));
	ft_lstfree(&lst, ptr);
	return (NULL);
}
