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

static char *get_line(char *repo)
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

static char *update_repo(char *repo)
{
	char	*new_repo;
	int		i;
	int		repo_len;

	i = 0;
	while (repo[i] && repo[i] != '\n')
		i++;
	i++;
	repo_len = ft_strlen(repo + i);
	new_repo = (char *)malloc(repo_len + 1);
	if (!new_repo)
	{
		free(repo);
		return (NULL);
	}
	ft_strcpy(new_repo, repo + i);
	free(repo);
	return (new_repo);
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

char *get_next_line(int fd)
{
    static char *repo;
    char buffer[BUFFER_SIZE + 1];
    char *line;
    int bytes_read;

    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buffer, 0) < 0)
        return (NULL);
    while (!check_newline(repo) && (bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        buffer[bytes_read] = '\0';
        repo = add_to_repo(repo, buffer);
        if (!repo)
            return (NULL);
    }
    if (!repo || !*repo)
        return (free(repo), repo = NULL, NULL);
    line = get_line(repo);
    repo = update_repo(repo);
	if (!repo)
		return (free(line), NULL);
    return (line);
}
