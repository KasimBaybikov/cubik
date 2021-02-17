# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvernon <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/09 20:48:10 by rvernon           #+#    #+#              #
#    Updated: 2021/02/15 15:29:51 by kasimbayb        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
SEP = \#\#\#\#\#\#\#

CC = gcc

MLX_D = libs/mlx/
LIB_D = libs/libft/

MLX = libmlx.dylib
LIB = libft.a

CFLAGS = -Wall -Wextra -Werror -I$(MLX_D) -Iincludes/ -I$(LIB_D)includes/ -fsanitize=address -Ofast

FILES = cub3d.c\
		error.c\

SRCS = $(addprefix srcs/, $(FILES))

OBJS = $(SRCS:.c=.o)


all: $(NAME)

$(NAME) : $(MLX) $(LIB) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -Llibs/libft/ -lft -L. -lmlx
	@echo "\033[1;32mDone!"
	@echo "\033[0m"

$(MLX) : $(MLX_D)
	@echo "\033[1;32m$(SEP) Compiling... $(SEP)\033[0;32m"
	@$(MAKE) -C $(MLX_D)
	mv $(MLX_D)$(MLX) .

$(LIB) : $(LIB_D)
	@$(MAKE) -C $(LIB_D)

clean:
	@echo "\033[1;31m$(SEP) Cleaning... $(SEP)\033[0;31m"
	@$(MAKE) -C $(MLX_D) clean
	@$(MAKE) -C $(LIB_D) clean
	$(RM) $(LIB_D)$(LIB)
	$(RM) $(OBJS)
	$(RM) $(MLX)
	@echo "\033[0m"

fclean : clean
	@echo "\033[1;31m$(SEP) Full Cleaning... $(SEP)\033[0;31m"
	$(RM) $(NAME)
	@echo "\033[0m"

re: fclean all
