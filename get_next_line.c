/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwrobles <rwrobles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:42:26 by rwrobles          #+#    #+#             */
/*   Updated: 2025/01/13 16:01:32 by rwrobles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Description of the functions in this file:
**
** int ft_check(char *str):
** This function checks for the presence of a newline character ('\n') in the 
** given string `str`. If found, it returns the index of the newline. Otherwise, 
** it returns -42, indicating the absence of a newline. It's also used to handle 
** null strings gracefully.
**
** char *ft_putline(char *keep):
** Extracts the current line from the string `keep`. If there is no newline, it 
** duplicates the entire string. Otherwise, it allocates memory for the line 
** (up to the first newline, inclusive) and returns it. Memory for the resulting 
** string is dynamically allocated and must be freed by the caller.
**
** char *ft_backup(char *keep):
** Creates a backup of the remaining content after the newline in the string 
** `keep`. If no newline is found or the string ends immediately after the 
** newline, it frees `keep` and returns NULL. Otherwise, it returns the new 
** backup string with the portion of `keep` after the newline.
**
** char *read_and_store(int fd, char *keep):
** Reads from the file descriptor `fd` and appends the read data to `keep`. The 
** function continues reading until a newline is found or the end of the file is 
** reached. If any read error occurs, it frees `keep` and returns NULL. This 
** function ensures that the entire file or buffer is read while maintaining 
** existing content in `keep`.
**
** char *get_next_line(int fd):
** The main function to retrieve the next line from the file descriptor `fd`. It 
** manages static storage (`keep`) to save unread data between calls. It uses 
** `read_and_store` to read new data, `ft_putline` to extract the next line, and 
** `ft_backup` to update `keep` for the remaining content. Returns the next line 
** or NULL if no more data is available.
*/

#include "get_next_line.h"

int	ft_check(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-42);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\0')
		return (-42);
	return (i);
}

char	*ft_putline(char *keep)
{
	char	*r_line;
	int		size;

	if (!keep || *keep == '\0')
		return (NULL);
	size = ft_check(keep);
	if (size == -42)
		return (ft_strdup(keep));
	r_line = (char *)malloc(sizeof(char) * (size + 2));
	if (!r_line)
		return (NULL);
	ft_memmove(r_line, keep, size);
	r_line[size] = '\n';
	r_line[size + 1] = '\0';
	return (r_line);
}

char	*ft_backup(char *keep)
{
	int		size;
	int		len;
	char	*new_keep;

	if (!keep || *keep == '\0')
		return (NULL);
	len = ft_strlen(keep);
	size = ft_check(keep);
	if (size == -42 || size >= len - 1)
	{
		free(keep);
		return (NULL);
	}
	new_keep = ft_substr(keep, size + 1, len - size - 1);
	free(keep);
	return (new_keep);
}

char	*read_and_store(int fd, char *keep, int r_read)
{
	char	*str;
	char	*temp;

	str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!str)
		return (NULL);
	while (ft_check(keep) == -42)
	{
		r_read = read(fd, str, BUFFER_SIZE);
		if (r_read <= 0)
			break ;
		str[r_read] = '\0';
		if (!keep)
			keep = ft_strdup(str);
		else
		{
			temp = keep;
			keep = ft_strjoin(keep, str);
			free(temp);
		}
	}
	free(str);
	if (r_read < 0)
		return (free(keep), NULL);
	return (keep);
}

char	*get_next_line(int fd)
{
	static char	*keep;
	char		*line;
	int			r_read;

	r_read = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	keep = read_and_store(fd, keep, r_read);
	if (!keep)
		return (NULL);
	line = ft_putline(keep);
	keep = ft_backup(keep);
	return (line);
}
