/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esir <esir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:21:06 by esir              #+#    #+#             */
/*   Updated: 2025/01/06 11:17:42 by esir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_strlen(char *a)
{
	int i;

	i = 0;
	while (a[i])
	{
		i++;
	}
	return (i);
}
char *ft_strcpy(char *dest, const char *src)
{
    int i;

	i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

char *ft_strncpy(char *dest, const char *src, size_t n)
{
    int i;

    i = 0;
    while (i < n && src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    while (i < n)
    {
       dest[i] = '\0';
      i++;
    }
    return (dest);
}