# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/29 08:32:05 by vbaudot           #+#    #+#              #
#    Updated: 2017/12/27 14:39:46 by vbaudot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = fractol
SRC = main.c\
		print_usage.c\
		fractol.c\
		events.c\
		draw_julia.c\
		draw_burning_ship.c\
		draw_mandelbrot.c\
		color.c\
		print_infos.c\

OBJ = $(SRC:.c=.o)
MLX = -L./minilibx_macos -lmlx -L./libft -lft -framework OpenGL -framework Appkit
DEBUG = #-g3 -fsanitize=address

CFLAGS = -Wall -Werror -Wextra
LIBFT = libft.a

YEL="\\033[33m"
BLU="\\033[34m"
RED="\\033[31m"
NC="\\033[0m"
MAG="\\033[35m"
CYA="\\033[36m"
GRE="\\033[32m"
BOL="\\033[1m"
CHE="\\xE2\\x9C\\x94"
OK="$(GRE)$(CHE)$(NC)"

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@printf "\n[$(NAME)] linking $(CYA)$(BOL)$(OBJ)$(NC)\n"
	@printf "to make the binary $(MAG)$(BOL)$(NAME)$(NC)"
	@gcc $(CFLAGS) $(MLX) $(OBJ) $(DEBUG) -o $(NAME)
	@printf '\t\t'$(OK)'\n'

%.o: %.c
	@printf "\r\033[0K[$(NAME)] compile $(BOL)$(YEL)$<$(NC)..."
	@$(CC) $(CFLAGS) -I./libft -I./minilibx_macos -c $<
	@printf '\t'$(OK)

clean:
	@make -C minilibx_macos clean
	@make -C libft clean
	@printf "[$(NAME)] rm all $(BOL)$(RED) obj file$(NC)"
	@rm -rf $(OBJ) libmlx.a
	@printf '\t\t'$(OK)'\n'

fclean: clean
	@make -C minilibx_macos clean
	@make -C libft fclean
	@printf "[$(NAME)] rm $(BOL)$(CYA)$(NAME)$(NC)"
	@rm -rf $(NAME)
	@printf '\t\t'$(OK)'\n'

re: fclean all

proper: all clean

.PHONY: re proper
