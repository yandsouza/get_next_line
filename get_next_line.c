/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynascime <yannssouza@outlook.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 15:19:53 by ynascime          #+#    #+#             */
/*   Updated: 2026/06/11 13:23:07 by ynascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	while (s[size] != '\0')
	{
		size++;
	}
	return (size);
}

//char *trim_line(char* stash)
//{
//}

char *next_line(char *stash)
{
	char *next;
	int next_len;
	int i;

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
	
	if (stash)
	{
		stash = NULL;
		return (stash);
	}
	buffer = malloc(11);
	buf_size = read(fd, buffer, 11);
	buffer[buf_size] = '\0';
	stash = buffer;
	return (stash);
}

char *get_next_line(int fd)
{
	char *line;
	static char *stash;
	
	stash = allocate_line(fd, stash);
	line = next_line(stash);
//	stash = trim_line(stash);
	return (line);
}

#include <stdio.h>
#include <fcntl.h>
int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		int fd;
		char *buf;

    	fd = open(argv[1], O_RDONLY);
		buf = get_next_line(fd);
		printf("%s", buf);
	}
	return (0);
}
