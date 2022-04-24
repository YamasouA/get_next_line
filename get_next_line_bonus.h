/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouta <asouta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 22:31:18 by asouta            #+#    #+#             */
/*   Updated: 2022/04/14 19:48:37 by asouta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include	<unistd.h>
# include	<stdlib.h>

typedef struct fd_list
{
	int				fd;
	char			*before;
	struct fd_list	*next;
}	t_fd_lst;

char		*get_next_line(int fd);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(char *s, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlen(const char *str);
t_fd_lst	*ft_lstadd(t_fd_lst **lst, int fd);
void		ft_lstfree(t_fd_lst **lst, t_fd_lst *target);
#endif
