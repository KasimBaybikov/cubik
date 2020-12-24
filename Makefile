# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kasimbaybikov <marvin@42.fr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/21 21:49:26 by kasimbayb         #+#    #+#              #
#    Updated: 2020/12/21 22:56:10 by kasimbayb        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRCS = sources/test.c\

HEADER = includes/cub3d.h

OBJS = ${SRCS:.c=.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror

MLX = ./minilibx

LXFLAGS = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJS)
	@echo "compile...."
	$(CC) -o $(NAME) -L $(MLX) $(LXFLAGS) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

