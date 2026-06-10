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
	char *buf;
	static char *stash;
	int i;

	buf = malloc(sizeof(char) * 1248);
	read(fd, buf, 1248);
	stash = ft_strdup(buf);
	i = 0;
	while (stash[i] != '\0')
	{
		if (stash[i] == '\n')
			stash[i] = '\0';
		i++;
	}
	return (stash);
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
