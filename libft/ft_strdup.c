/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:05:00 by vcodrean          #+#    #+#             */
/*   Updated: 2023/03/02 16:54:49 by vcodrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Ft_strdup() allocates memory for a copy of the string s1,
 *  does the copy, and returns a pointer to it
 * 
 * param char s1 The string to be copied.
 * 
 * return A pointer to a new string that is a duplicate of the string s1.
 */
char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int		size;

	size = ft_strlenl(s1);
	ptr = malloc(sizeof(char) * (size + 1));
	if (ptr == NULL)
		return (NULL);
	ft_memcpy(ptr, s1, size);
	ptr[size] = '\0';
	return (ptr);
}
