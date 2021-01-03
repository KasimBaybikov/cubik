# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kasimbaybikov <marvin@42.fr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/21 21:49:26 by kasimbayb         #+#    #+#              #
#    Updated: 2021/01/04 01:16:40 by kasimbayb        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
SEP = \#\#\#\#\#\#\#

LIBFT = libft/
SRCS = sources/cub3d.c\
	   sources/color.c\
	   sources/error.c\
	   sources/initials.c

HEADER = includes/cub3d.h

OBJS = ${SRCS:.c=.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror

MLX = mlx/

LXFLAGS = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(LIBFT)libft.a $(OBJS)
	@cp $(MLX)libmlx.dylib libmlx.dylib
	@cp $(LIBFT)libft.a ./$(NAME).a
	$(CC) ./$(NAME).a -o $(NAME) -L $(MLX) $(LXFLAGS) $(OBJS)
	@echo "\033[1;32mDone!"
	@echo "\033[0m"

$(LIBFT)libft.a: $(LIBFT)
	@echo "\033[1;32m$(SEP) Compiling... $(SEP)\033[0;32m"
	@$(MAKE) -C $(LIBFT)

clean:
	@echo "\033[1;31m$(SEP) Cleaning... $(SEP)\033[0;31m"
	@$(MAKE) -C $(LIBFT) clean
	$(RM) $(OBJS)
	@echo "\033[0m"

fclean: clean
	@echo "\033[1;31m$(SEP) Full Cleaning... $(SEP)\033[0;31m"
	$(RM) $(NAME) libmlx.dylib $(NAME).a
	$(RM) $(LIBFT)libft.a
	@echo "\033[0m"

re: fclean all

.PHONY: all clean fclean re