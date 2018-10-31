# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbauer <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/31 17:10:45 by tbauer            #+#    #+#              #
#    Updated: 2018/10/31 17:31:34 by tbauer           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FLAGS = -Werror -Wextra -Wall

CC = gcc

SRC = main2.c lecture.c fdf.c key.c ft_error.c

OBJ = $(SRC:.c=.o)

$(NAME):
	@make -C libft/ fclean && make -C libft
	@make -C minilibx_macos/ clean && make -C minilibx_macos
	@$(CC) $(FLAGS) $(SRC)  -c -I./libft/includes
	@$(CC) -o $(NAME) $(OBJ) -L./minilibx_macos -lmlx -framework OpenGL -framework Appkit -L./libft -lft

all: $(NAME)

clean:
	@rm -f $(OBJ)
	@make -C libft/ clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft/ fclean
	@make -C minilibx_macos/ clean

re: fclean all
