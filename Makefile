# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvernon <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/09 20:48:10 by rvernon           #+#    #+#              #
#    Updated: 2021/02/27 19:50:57 by rvernon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
SEP = \#\#\#\#\#\#\#

CC = gcc

MLX_D = libs/mlx/
LIB_D = libs/libft/

MLX = libmlx.dylib
LIB = libft.a

CFLAGS = -g -I$(MLX_D) -Iincludes/ -I$(LIB_D)includes/ -framework OpenGL -framework AppKit

FILES = start.c\
		error.c\
		main.c\
		init_all.c\
		parse_file.c\
		parse_map.c\
		get.c\
		get_f.c\
		get_c.c\
		get_pos_plr.c\
		get_sprites.c\
		utils.c\
		calculate.c\
		mlx.c\
		key_down.c\
		key_up.c\
		floor_paint.c\
		ceiling_paint.c\
		new_keys.c\
		move.c\

SRCS = $(addprefix srcs/, $(FILES))

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(MLX) $(OBJS) $(LIB_D)$(LIB)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -Llibs/libft/ -lft -L. -lmlx
	@echo "\033[1;32mDone!"
	@echo "\033[0m"

$(MLX) : $(MLX_D)
	@echo "\033[1;32m$(SEP) Compiling... $(SEP)\033[0;32m"
	@$(MAKE) -C $(MLX_D)
	#mv $(MLX_D)$(MLX) .

$(LIB_D)$(LIB) :
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

.PHONY: all clean fclean re
