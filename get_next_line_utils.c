/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwrobles <rwrobles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:43:25 by rwrobles          #+#    #+#             */
/*   Updated: 2025/01/13 16:01:32 by rwrobles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
 size_t ft_strlen(const char *str):
** Calculates the length of the given string `str`. If the string is NULL, it 
** returns 0. This function is used throughout the program to handle dynamic 
** string operations.
**
** char *ft_strdup(const char *str):
** Allocates memory and creates a duplicate of the given string `str`. The 
** function returns the duplicated string or NULL if the allocation fails.
**
** char *ft_substr(char const *s, unsigned int start, size_t len):
** Extracts a substring from the string `s`, starting at the `start` index and 
** copying up to `len` characters. If the starting index is out of bounds, it 
** returns an empty string. The result is dynamically allocated.
**
** void *ft_memmove(void *dst, const void *src, size_t len):
** Copies `len` bytes from the memory area `src` to `dst`. It handles 
** overlapping memory areas correctly, ensuring that data is not 
** corrupted during the copy process. Returns the destination pointer.
**
** char *ft_strjoin(const char *s1, const char *s2):
** Concatenates two strings, `s1` and `s2`, into a new dynamically allocated 
** string. Frees the memory of the first string (`s1`) after concatenation. 
** Returns the concatenated string or NULL if memory allocation fails.
*/

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *str)
{
	unsigned int	i;
	size_t			len;
	char			*save;

	i = 0;
	len = ft_strlen(str);
	save = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (i < len)
	{
		save[i] = str[i];
		i++;
	}
	save[i] = 0;
	return (save);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	length;

	if (!s)
		return (NULL);
	length = ft_strlen(s);
	if (start >= length)
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = 0;
	return (str);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (dst == src || len == 0)
		return (dst);
	i = -1;
	if (dst > src)
		while (len--)
			((char *)dst)[len] = ((char *)src)[len];
	else
		while (++i < len)
			((char *)dst)[i] = ((char *)src)[i];
	return (dst);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!str)
		return (NULL);
	if (s1)
		ft_memmove(str, s1, s1_len);
	if (s2)
		ft_memmove(str + s1_len, s2, s2_len);
	str[s1_len + s2_len] = '\0';
	return (str);
}
