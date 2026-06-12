/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynascime <yannssouza@outlook.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 17:41:54 by ynascime          #+#    #+#             */
/*   Updated: 2026/06/10 17:46:18 by ynascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_strlen(const char *s)
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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dst;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	size_t	e;

	if (!s2)
		return (NULL);
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	dst = malloc(s1_len + s2_len + 1);
	if (!dst)
		return (0);
	i = 0;
	e = 0;
	while (s1[i] != '\0')
		dst[e++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		dst[e++] = s2[i++];
	dst[e] = '\0';
	return (dst);
}
