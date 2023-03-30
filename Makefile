# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/20 13:18:21 by vcodrean          #+#    #+#              #
#    Updated: 2023/03/30 18:13:34 by vcodrean         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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

NAME = so_long

CC = gcc 
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address  
RM = rm -f
LIBFT_PATH = libft/
FT_PRINTF_PATH = ft_printf/
SRC_PATH = ./src/

SRC = main.c ../gnl/get_next_line_utils.c ../gnl/get_next_line.c sl_vaid_map.c\
		sl_map_size.c sl_errors.c sl_grid.c sl_img.c sl_valid_path.c

SRCS = $(addprefix $(SRC_PATH), $(SRC))
 
OBJS = $(SRCS:.c=.o)

%.o:%.c
		@echo "${BLUE} ◎ $(BROWN)Compiling   ${MAGENTA}→   $(CYAN)$< $(DEF_COLOR)"
		@$(CC) $(CFLAGS) -c $< -o $@ -I $(LIBFT_PATH)
		@$(CC) $(CFLAGS) -c $< -o $@ -I $(FT_PRINTF_PATH)

all: $(NAME)  

$(NAME): $(OBJS)
		@make -C $(LIBFT_PATH) --silent
		@make -C $(FT_PRINTF_PATH) --silent
		@$(CC) $(CFLAGS) $(OBJS)  -o $(NAME)  -I./libft -L./libft -lft -I./ft_printf -L./ft_printf -lftprintf -lmlx -framework OpenGL -framework AppKit -lz
		@echo "\n$(GREEN) Created $(EXEC) ✓ $(DEF_COLOR)\n"


clean:
		@$(RM) $(OBJS)
		@make -C $(LIBFT_PATH) clean --silent
		@make -C $(FT_PRINTF_PATH) clean --silent
		@echo "\n${BLUE} ◎ $(RED)All objects cleaned successfully ${BLUE}◎$(DEF_COLOR)\n"

fclean: clean
		@$(RM) $(NAME)
		@$(RM) $(OBJS)
		@make -C $(LIBFT_PATH) fclean --silent
		@make -C $(FT_PRINTF_PATH) fclean --silent
		@echo "\n${BLUE} ◎ $(RED)All objects and executable cleaned successfully${BLUE} ◎$(DEF_COLOR)\n"

re: fclean all

.PHONY: all clean fclean re
