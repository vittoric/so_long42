/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:49:27 by vcodrean          #+#    #+#             */
/*   Updated: 2023/01/17 12:37:50 by vcodrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			*line;
	static char		*depot = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if ((depot && !ft_strchar(depot, '\n')) || !depot)
		depot = readbuff(fd, depot);
	if (!depot)
		return (NULL);
	line = new_line(depot);
	if (!line)
		return (ft_free(&depot));
	depot = clean_depot(depot);
	return (line);
}

char	*readbuff(int fd, char *depot)
{
	int		to_read;
	char	*buffer;

	if (fd < 0)
		return (NULL);
	to_read = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (ft_free(&depot));
	buffer[0] = '\0';
	while (to_read > 0 && !ft_strchar(buffer, '\n'))
	{
		to_read = read (fd, buffer, BUFFER_SIZE);
		if (to_read > 0)
		{
			buffer[to_read] = '\0';
			depot = gnl_strjoin(depot, buffer);
		}
	}
	free(buffer);
	if (to_read == -1)
		return (ft_free(&depot));
	return (depot);
}

char	*new_line(char *depot)
{
	char	*line;
	char	*p;
	int		len;

	p = ft_strchar(depot, '\n');
	len = p - depot + 1;
	line = gnl_substr(depot, 0, len);
	if (!line)
		return (NULL);
	return (line);
}

char	*clean_depot(char *depot)
{
	char	*new_depot;
	char	*p;
	int		len;

	p = ft_strchar(depot, '\n');
	if (!p)
	{
		new_depot = NULL;
		return (ft_free(&depot));
	}
	else
		len = (p - depot) + 1;
	if (!depot[len])
		return (ft_free(&depot));
	new_depot = gnl_substr(depot, len, gnl_strlen(depot) - len);
	ft_free(&depot);
	if (!new_depot)
		return (NULL);
	return (new_depot);
}

char	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}
