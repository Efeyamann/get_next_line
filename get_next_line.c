/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esir <esir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:19:37 by esir              #+#    #+#             */
/*   Updated: 2025/01/06 11:49:31 by esir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

static char add_to_repo(char *repo, char *buffer)
{
	int i;
	int k;
	
	k = 0;
	i = ft_strlen(repo);
	while(buffer[k])
	{
		repo[i] = buffer[k];
		i++;
		k++;
	}
	return (repo);
}

int check_newline(char *repo)
{
	int i;
	
	i = 0;
	while(repo[i])
	{
		if (repo[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char *get_line(char *repo)
{
	char *line;
	int i;
	int k;
	
	i = 0;
	k = 0;
	while (repo[i] && repo[i] == '\n')
		i++;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	while ()
	return (line);
}

char *get_next_line(int fd)
{
	char			buffer[BUFFER_SIZE + 1];
	static char		*repo = NULL;
	char			*line = NULL;
	int				bytes_read;
	
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buffer, 0) < 0)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		repo = add_to_repo(repo, buffer);
		if (check_newline(repo) == 1)
			break;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (repo && check_newline(repo))
		line = get_line(repo);
	
}