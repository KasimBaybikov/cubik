# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvernon <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/09 20:48:10 by rvernon           #+#    #+#              #
#    Updated: 2021/03/06 20:15:09 by rvernon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
SEP = \#\#\#\#\#\#\#

CC = gcc

MLX_D = libs/mlx/
LIB_D = libs/libft/

MLX = libmlx.a
LIB = libft.a

CFLAGS = -g -I$(MLX_D) -Iincludes/ -I$(LIB_D)includes/

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
		textures_make.c\
		sprite_casting.c\
		screen.c\
		free_all.c\
		skip.c\

SRCS = $(addprefix srcs/, $(FILES))

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(MLX_D)$(MLX) $(OBJS) $(LIB_D)$(LIB)
	$(CC)  $(CFLAGS) -o $(NAME) -framework OpenGL -framework AppKit $(OBJS) -Llibs/libft/ -lft -Llibs/mlx -lmlx
	@echo "\033[1;32mDone!"
	@echo "\033[0m"

$(MLX_D)$(MLX) : $(MLX_D)
	@echo "\033[1;32m$(SEP) Compiling... $(SEP)\033[0;32m"
	@$(MAKE) -C $(MLX_D) 2>/dev/null

$(LIB_D)$(LIB) : $(LIB_D)
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
