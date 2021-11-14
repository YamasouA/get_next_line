/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouta <asouta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 22:31:18 by asouta            #+#    #+#             */
/*   Updated: 2021/11/08 22:44:33 by asouta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>

typedef struct fd_list
{
    int fd;
    char  *before;
    struct fd_list  *next;
}   fd_lst;

#include <stdio.h>
char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char    *ft_strdup(char *s, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
fd_lst  *ft_lstadd(fd_lst **lst, int fd);
void  ft_lstfree(fd_lst **lst, fd_lst *target);
fd_lst  *ft_lstnew(int fd);
#endif
