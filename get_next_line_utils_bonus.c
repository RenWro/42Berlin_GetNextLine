/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwrobles <rwrobles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:43:05 by rwrobles          #+#    #+#             */
/*   Updated: 2025/01/13 21:38:35 by rwrobles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Bonus Notes:
** The bonus version of get_next_line is designed to handle multiple file 
** descriptors simultaneously. Each file descriptor maintains its own static 
** storage, allowing the function to correctly manage and return lines from 
** multiple files or inputs without interference.

** Note: The functions in get_next_line_utils_bonus.c are identical to those 
** in get_next_line_utils.c. No modifications are needed, as these utility 
** functions remain general-purpose and are reused for both the standard 
** and bonus implementations.
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
	str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!str)
		return (NULL);
	ft_memmove(str, s1, s1_len);
	ft_memmove(str + s1_len, s2, s2_len);
	str[s1_len + s2_len] = '\0';
	return (str);
}
