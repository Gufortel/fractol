# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Gufortel <gufortel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/30 17:14:20 by gufortel          #+#    #+#              #
#    Updated: 2019/07/24 13:36:18 by Gufortel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

FLAG = -Wall -Wextra -Werror

SRC = frt.c\
	image.c\
	main.c\

OBJ = $(SRC:.c=.o)

INC = fractol.h

all: $(NAME)

source:
	@make -C ./libft/
	@make -C ./minilibx_macos/

$(NAME): source $(OBJ) $(SRC) $(INC)
	@gcc -c $(FLAG) $(SRC) 
	@gcc -o $(NAME) $(OBJ) $(FLAG) -L minilibx_macos -lmlx -framework OpenGL -framework AppKit  ./libft/libft.a

clean:
	@make -C ./libft/ clean
	@make -C ./minilibx_macos/ clean
	@rm -Rf $(OBJ)

fclean: clean
	@make -C ./libft/ fclean
	@make -C ./minilibx_macos/ clean
	@rm -Rf $(NAME)

re:	fclean all
