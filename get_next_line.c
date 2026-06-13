/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynascime <yannssouza@outlook.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 15:19:53 by ynascime          #+#    #+#             */
/*   Updated: 2026/06/12 18:30:35 by ynascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*allocate_line(int fd, char *stash)
{
	char	*buffer;
	size_t	buf_size;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (0);
	while (!ft_strchr(stash, '\n'))
	{
		buf_size = read(fd, buffer, BUFFER_SIZE);
		if (buf_size <= 0)
		{
			free(buffer);
			free(stash);
			return (0);
		}
		buffer[buf_size] = '\0';
		stash = ft_strjoin(stash, buffer);
	}
	free(buffer);
	return (stash);
}

char	*next_line(char *stash)
{
	char	*next;
	int		i;

	i = 0;
	next = malloc(sizeof(char) * (ft_strlen(stash) + 2));
	if (!next)
		return (0);
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

char	*trim_line(char *stash)
{
	int		i;
	int		e;
	char	*new_stash;

	i = 0;
	while (stash[i] != '\0' && stash[i] != '\n')
		i++;
	i++;
	new_stash = malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	if (!new_stash)
		return (0);
	e = 0;
	while (stash[i] != '\0')
		new_stash[e++] = stash[i++];
	new_stash[e] = '\0';
	free(stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	stash = allocate_line(fd, stash);
	if (!stash)
		return (0);
	line = next_line(stash);
	stash = trim_line(stash);
	return (line);
}
/*#include <stdio.h>
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
}*/
