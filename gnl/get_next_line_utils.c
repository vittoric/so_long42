/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:11:29 by vcodrean          #+#    #+#             */
/*   Updated: 2023/01/16 17:42:56 by vcodrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_strjoin(char *depot, char *buf)
{
	char	*str;
	size_t	i;
	size_t	c;

	if (!depot)
	{
		depot = malloc(sizeof(char) + 1);
		if (!depot)
			return (NULL);
		depot[0] = 0;
	}
	str = (char *)malloc(sizeof(char) * gnl_strlen(depot) + gnl_strlen(buf) + 1);
	if (!str)
		return (ft_free(&depot));
	i = -1;
	while (depot[++i])
		str[i] = depot[i];
	c = -1;
	while (buf[++c])
		str[i + c] = buf[c];
	str[i + c] = '\0';
	free(depot);
	return (str);
}

char	*gnl_substr(char *depot, unsigned int start, size_t len)
{
	size_t	i;
	char	*res;

	i = 0;
	if (!depot)
		return (0);
	if (start > gnl_strlen(depot))
	{
		res = malloc(sizeof(char) * (1));
		if (!res)
			return (NULL);
		res[0] = '\0';
		return (res);
	}
	if (gnl_strlen(depot) - start < len)
		len = gnl_strlen(depot) - start;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	while (start < gnl_strlen(depot) && i < len && depot[start])
		res[i++] = depot[start++];
	res[i] = '\0';
	return (res);
}

size_t	gnl_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchar(char *depot, int c)
{
	int		i;

	i = 0;
	while (depot[i] != '\0')
	{
		if (depot[i] == (char)c)
			return (&((char *)depot)[i]);
		i++;
	}
	if ((char)c == '\0')
		return (&((char *)depot)[i]);
	return (0);
}
