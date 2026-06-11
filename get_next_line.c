/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynascime <yannssouza@outlook.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 15:19:53 by ynascime          #+#    #+#             */
/*   Updated: 2026/06/10 17:52:03 by ynascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	char *line;
	static char *stash;
	char *buff;
	int buff_size;

	if (stash)
	{
		stash = NULL;
		return (stash);
	}

	buff = malloc(sizeof(char) * 12);
	buff_size = read(fd, line, 12);
	buff[buff_size] = '\0';
	stash = ft_strjoin(buff, line);
	return (stash);
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
