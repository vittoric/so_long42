/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:15:59 by vcodrean          #+#    #+#             */
/*   Updated: 2023/01/16 17:41:34 by vcodrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <string.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

char	*get_next_line(int fd);
char	*readbuff(int fd, char *depot);
char	*new_line(char *depot);
char	*ft_strchar(char *depot, int c);
char	*ft_free(char **str);
char	*gnl_strjoin(char *depot, char *buf);
char	*gnl_substr(char *depot, unsigned int start, size_t len);
size_t	gnl_strlen(char *str);
char	*clean_depot(char *depot);

#endif