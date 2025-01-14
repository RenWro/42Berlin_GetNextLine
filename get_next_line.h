/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwrobles <rwrobles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:42:38 by rwrobles          #+#    #+#             */
/*   Updated: 2025/01/13 16:01:34 by rwrobles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** BUFFER_SIZE defines the number of bytes to be read from the file (or file 
** descriptor) with each call to the `read()` function. It determines the 
** chunk size for each reading operation, directly impacting:
**  - The number of system calls (`read()`) needed.
**  - The amount of temporary memory allocated for processing each read.
** In this project, a small BUFFER_SIZE, like 32, was chosen to minimize
** memory usage and ensure compatibility with systems with limited stack space.

** The <fcntl.h> library provides file control options, constants, and
** declarations used for low-level file operations. It is required for
** functions like `open()` and constants such as `O_RDONLY`, which
** specifies that the file should be opened in read-only mode.
*/

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *str);
void	*ft_memmove(void *dst, const void *src, size_t len);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
