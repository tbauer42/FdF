# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbauer <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/31 17:10:45 by tbauer            #+#    #+#              #
#    Updated: 2018/11/01 21:05:00 by tbauer           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FLAGS = -Werror -Wextra -Wall

CC = gcc

SRC = main2.c lecture.c fdf.c key.c ft_error.c

OBJ = $(addprefix $(O_DIR)/,$(SRC:.c=.o))

O_DIR = ./objs

$(NAME): $(OBJ)
	@make -C libft/ fclean && make -C libft
	@make -C minilibx_macos/ clean && make -C minilibx_macos
	@$(CC) -o $(NAME) $(OBJ) -L./minilibx_macos -lmlx -framework OpenGL -framework Appkit -L./libft -lft

$(O_DIR)/%.o: %.c
	@mkdir -p $(O_DIR)
	@$(CC) $(FLAGS) -o $@ -c $<

all: $(NAME)

clean:
	@rm -f $(OBJ)
	@rm -rf $(O_DIR)
	@make -C libft/ clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft/ fclean
	@make -C minilibx_macos/ clean

re: fclean all
