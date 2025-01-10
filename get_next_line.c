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

static char *add_to_repo(char *repo, char *buffer)
{
	char *new_repo;
	int repo_len;
	int buffer_len;

	repo_len = 0;
	buffer_len = ft_strlen(buffer);
	if (repo)
		repo_len = ft_strlen(repo);
	new_repo = (char *)malloc(repo_len + buffer_len + 1);
	if (!new_repo)
		return (NULL);
	if (repo)
	{
		ft_strcpy(new_repo, repo);
		free(repo);
	}
	ft_strcpy(new_repo + repo_len, buffer);
	return(new_repo);
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

	i = 0;
	while (repo[i] && repo[i] != '\n')
		i++;
	line = (char *)malloc(i + 2);
	if (!line)
		return (NULL);
	ft_strncpy(line, repo, i);
	line[i] = '\0';
	return (line);
}

char *check_and_free_repo(char **repo, int bytes_read)
{
	if (repo == NULL || *repo == '\0' || bytes_read == -1)
	{
		free(*repo);
		*repo = NULL;
	}
	return (NULL);
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
	check_and_free_repo(repo, bytes_read);
	if (bytes_read == 0)
		return (repo);
	if (repo && check_newline(repo))
		line = get_line(repo);
	return (line);
}
