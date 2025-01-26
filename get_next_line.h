/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esir <esir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 16:41:32 by esir              #+#    #+#             */
/*   Updated: 2025/01/26 16:57:21 by esir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 25
# endif

# include <stdlib.h>

size_t	ft_strlen(char *a);
char	*ft_strncpy(char *dest, const char *src, size_t n);
char	*get_next_line(int fd);
char	*ft_strdup(char *src);
char	*ft_strchr(const char *s, int c);

#endif