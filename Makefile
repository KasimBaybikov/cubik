# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kasimbaybikov <marvin@42.fr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/21 21:49:26 by kasimbayb         #+#    #+#              #
#    Updated: 2021/01/02 14:48:07 by kasimbayb        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
SEP = \#\#\#\#\#\#\#

SRCS = sources/test.c\

HEADER = includes/cub3d.h

OBJS = ${SRCS:.c=.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror

MLX = mlx/

LXFLAGS = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJS)
	@echo "\033[1;32m$(SEP) Compiling... $(SEP)\033[0;32m"
	@cp $(MLX)libmlx.dylib libmlx.dylib
	$(CC) -o $(NAME) -L $(MLX) $(LXFLAGS) $(OBJS)
	@echo "\033[1;32mDone!"
clean:
	@echo "\033[1;31m$(SEP) Cleaning... $(SEP)\033[0;31m"
	$(RM) $(OBJS)
	@echo "\033[0m"

fclean: clean
	@echo "\033[1;31m$(SEP) Full Cleaning... $(SEP)\033[0;31m"
	$(RM) $(NAME) libmlx.dylib
	@echo "\033[0m"

re: fclean all

