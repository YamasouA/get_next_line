/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouta <asouta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 13:59:25 by asouta            #+#    #+#             */
/*   Updated: 2021/11/08 23:44:24 by asouta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *ft_strchr(const char *s, int c)
{
  char    *temp;

  if (s == NULL)
    return (NULL);
	temp = (char *)s;
  while (*temp)
  {
		if (*temp == (const char)c)
			return (temp);
		temp++;
  }
  if (c == 0)
	  return (temp);
  return (NULL);
}

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
  char    *ptr;
  size_t  min_len;

	if (s == NULL)
		return (NULL);
  if (ft_strlen(s) <= start)
  {
		ptr = (char *)malloc(sizeof(char));
		if (ptr == NULL)
			return (NULL);
		*ptr = '\0';
		return (ptr);
  }
  min_len = len;
  if (len > ft_strlen(s))
    min_len = ft_strlen(s);
  ptr = (char *)malloc(sizeof(char) * (min_len + 1));
  if (ptr == NULL)
		return (NULL);
  ft_strlcpy(ptr, s + start, min_len + 1);
  return (ptr);
}

char    *ft_strjoin(char const *s1, char const *s2)
{
  char    *s_join;
  char    *ptr_cpy;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
  s_join = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
  ptr_cpy = s_join;
  if (s_join == NULL)
		return (NULL);
  ft_strlcpy(s_join, s1, ft_strlen(s1) + 1);
  s_join += ft_strlen(s1);
  ft_strlcpy(s_join, s2, ft_strlen(s2) + 1);
  return (ptr_cpy);
}

size_t  ft_strlen(const char *str)
{
  size_t  cnt;

  if (str == NULL)
    return (0);
	cnt = 0;
  while (*str++)
		cnt++;
  return (cnt);
}

size_t  ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
    size_t  src_len;
    size_t  i;

    src_len = ft_strlen(src);
    i = 0;
    if (dstsize <= 0)
        return (src_len);
    while (i < dstsize - 1 && i < src_len)
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return (src_len);
}