/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esir <esir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:19:37 by esir              #+#    #+#             */
/*   Updated: 2025/01/18 15:58:30 by esir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

static char	*add_to_repo(char *repo, char *buffer)
{
	char	*new_repo;
	int		repo_len;
	int		buffer_len;

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
	return (new_repo);
}

static char	*get_line(char *repo)
{
	char	*line;
	int		i;

	if (!repo)
		return (NULL);
	i = 0;
	while (repo[i] && repo[i] != '\n')
		i++;
	line = (char *)malloc(i + 2);
	if (!line)
		return (NULL);
	ft_strncpy(line, repo, i);
	if (repo[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*update_repo(char *repo)
{
	char	*new_repo;
	int		i;

	i = 0;
	while (repo[i] && repo[i] != '\n')
		i++;
	if (repo[i] == '\n')
		i++;
	if (repo[i] == '\0' && !repo[0])
	{
		free(repo);
		return (NULL);
	}
	new_repo = ft_strdup(repo + i);
	if (!new_repo)
		return (NULL);
	free(repo);
	return (new_repo);
}

static char	*read_and_store(int fd, char *repo)
{
	char	*buffer;
	int		bytes_read;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		repo = add_to_repo(repo, buffer);
		if (!repo)
			return (free(buffer), NULL);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	if (bytes_read == -1)
		return (free(repo), NULL);
	return (repo);
}

char	*get_next_line(int fd)
{
	static char	*repo = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	repo = read_and_store(fd, repo);
	if (!repo)
		return (NULL);
	line = get_line(repo);
	if (!line)
		return (free(repo), NULL);
	repo = update_repo(repo);
	if (!repo)
		return (free(line), NULL);
	return (line);
}
