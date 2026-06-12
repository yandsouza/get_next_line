/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynascime <yannssouza@outlook.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 15:19:53 by ynascime          #+#    #+#             */
/*   Updated: 2026/06/11 17:31:35 by ynascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	size;

	if (!s)
		return (0);
	size = 0;
	while (s[size] != '\0')
	{
		size++;
	}
	return (size);
}

char *trim_line(char* stash)
{
	int i;
	int e;
	char *new_stash;

	i = 0;
	while(stash[i] != '\0' && stash[i] != '\n')
		i++;
	if (!stash[i])
		return (0);
	i++;
	new_stash = malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	e = 0;
	while (stash[i] != '\0')
		new_stash[e++] = stash[i++];
	new_stash[e] = '\0';
	free(stash);
	return (new_stash);
}

char *next_line(char *stash)
{
	char *next;
	int next_len;
	int i;
	
	if (!stash)
		return (0);

	i = 0;
	next = malloc(sizeof(char) * (ft_strlen(stash) + 2));	
	while (stash[i] != '\0' && stash[i] != '\n')
	{
		next[i] = stash[i];	
		i++;
	}
	next[i] = '\n';
	i++;
	next[i] = '\0';
	return (next);	
}

char *allocate_line(int fd, char *stash)
{
	char *buffer;
	size_t buf_size;
	
	buffer = malloc(11);
	buf_size = read(fd, buffer, 11);
	if (buf_size == 0)
		return (0);
	buffer[buf_size] = '\0';
	stash = ft_strjoin(stash, buffer);
	return (stash);
}

char *get_next_line(int fd)
{
	char *line;
	static char *stash;
	
	stash = allocate_line(fd, stash);
	if (!stash)
		return (0);
	line = next_line(stash);
	stash = trim_line(stash);
	return (line);
}

#include <stdio.h>
#include <fcntl.h>
int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		int fd = open(argv[1], O_RDONLY);
		char	*line;
		while ((line = get_next_line(fd)))
		{
			if (!line)
				break;
			printf("%s", line);
			free(line);
		}
	}
	return (0);
}
