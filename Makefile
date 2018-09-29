#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azaporoz <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/11 15:27:53 by azaporoz          #+#    #+#              #
#    Updated: 2018/09/29 20:06:07 by ikoloshy         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fractol
FLG = -Wall -Wextra -Werror
FRM = -framework AppKit -framework OpenGL
SRC = src/main.c \
	  src/init_start.c \

HDR = includes/fractol.h
OFL = $(SRC:.c=.o)
LIB = libft/libft.a
MLX = -lmlx -I minilibx_macos -L minilibx_macos

.NOTPARALLEL: all clean fclean re

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIB) $(OFL) 
	@gcc $(FLG) -o $@ $(OFL) -I $(HDR) -L libft/ -lft $(MLX) $(FRM)
	@echo "\033[1;32mFdF is ready to work\033[0m"

%.o: %.c $(HDR) $(LIB)
	@gcc -c $< -o $@ $(FLG) 
$(LIB):
	@make -C ./libft

clean:
	@/bin/rm -f $(OFL)
	@make fclean -C ./libft
	@echo "\033[1;32mObjects files FDF were deleted\033[0m"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "\033[1;32mFDF was deleted\033[0m"

re: fclean all
