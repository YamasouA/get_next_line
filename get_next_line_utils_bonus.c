#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	char	*temp;

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

char	*ft_strdup(char *s, size_t len)
{
	char	*ptr;
	char	*ptr_cpy;

	if (s == NULL)
		return (NULL);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	ptr_cpy = ptr;
	if (ptr == NULL)
		return (NULL);
	while (len--)
		*ptr++ = *s++;
	*ptr = '\0';
	return (ptr_cpy);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s_join;
	char	*ptr_cpy;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s_join = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	ptr_cpy = s_join;
	if (s_join == NULL)
		return (NULL);
	while (*s1 != '\0')
		*s_join++ = *s1++;
	while (*s2 != '\0')
		*s_join++ = *s2++;
	*s_join = '\0';
	return (ptr_cpy);
}

size_t	ft_strlen(const char *str)
{
	size_t	cnt;

	if (str == NULL)
		return (0);
	cnt = 0;
	while (*str++)
		cnt++;
	return (cnt);
}
