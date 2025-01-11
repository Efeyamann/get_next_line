/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esir <esir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:21:09 by esir              #+#    #+#             */
/*   Updated: 2025/01/06 10:39:37 by esir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEX_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 15
#endif

#include <stdlib.h>

int     ft_strlen(char *a);
char    *ft_strcpy(char *dest, const char *src);
char    *ft_strncpy(char *dest, const char *src, size_t n);
char    *get_next_line(int fd);
int     check_newline(char *repo);

#endif