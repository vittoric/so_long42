# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/20 13:18:21 by vcodrean          #+#    #+#              #
#    Updated: 2023/03/20 17:35:47 by vcodrean         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

DEL_LINE =		\033[2K
ITALIC =		\033[3m
BOLD =			\033[1m
DEF_COLOR =		\033[0;39m
GRAY =			\033[0;90m
RED =			\033[0;91m
GREEN =			\033[0;92m
YELLOW =		\033[0;93m
BLUE =			\033[0;94m
MAGENTA =		\033[0;95m
CYAN =			\033[0;96m
WHITE =			\033[0;97m
BLACK =			\033[0;99m
ORANGE =		\033[38;5;209m
BROWN =			\033[38;2;184;143;29m
DARK_GRAY =		\033[38;5;234m
MID_GRAY =		\033[38;5;245m
DARK_GREEN =	\033[38;2;75;179;82m
DARK_YELLOW =	\033[38;5;143m

SRCS =main.c
OBJS = ${SRCS:.c=.o}
LIBFTPATH = ./libft/

CC = gcc
CFLAGS = -Wall -Wextra -Werror 
MLXF = -lmlx -framework OpenGL -framework AppKit -lz 
FSANIT = -g3 -fsanitize=address  -O
RM = rm -f

%.o: %.c
	@echo "${BLUE} ◎ $(BROWN)Compiling   ${MAGENTA}→   $(CYAN)$< $(DEF_COLOR)"
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(LIBFT_PATH)

$(NAME): $(OBJS)
	@make -C $(LIBFT_PATH) --silent
	@$(CC) $(CFLAGS) ${SRCS} -o $(EXEC)  -I./libft -L./libft -lft
	@echo "\n$(GREEN) Created $(EXEC) ✓ $(DEF_COLOR)\n"

all: $(NAME)

clean:
	@$(RM) $(OBJS)
	@make -C $(LIBFT_PATH) clean --silent
	@echo "\n${BLUE} ◎ $(RED)All objects cleaned successfully ${BLUE}◎$(DEF_COLOR)\n"

fclean:  clean
	@$(RM) $(NAME)
	@$(RM) $(OBJS)
	@make -C $(LIBFT_PATH) fclean --silent
	@echo "\n${BLUE} ◎ $(RED)All objects and executable cleaned successfully${BLUE} ◎$(DEF_COLOR)\n"
	
re: fclean all

.PHONY: all clean fclean re