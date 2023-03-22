# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/20 13:18:21 by vcodrean          #+#    #+#              #
#    Updated: 2023/03/22 11:58:51 by vcodrean         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c gnl/get_next_line_utils.c gnl/get_next_line.c sl_vaid_map.c

OBJS = $(SRCS:.c=.o)

NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

%.o:%.c
		$(CC) $(CFLAGS) -Imlx -c $< -o $(<:.c=.o) 

RM = rm -f

$(NAME): $(OBJS)

		$(CC) $(CFLAGS) $(OBJS)  -o $(NAME)  

all: $(NAME)  


sanitize: $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -Imlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) 

clean:
			$(RM) $(OBJS)

fclean: clean
			$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
