# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvernon <rvernon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/30 13:32:12 by rvernon           #+#    #+#              #
#    Updated: 2020/12/30 23:31:05 by kasimbayb        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = ft_memset.c\
	   ft_bzero.c\
	   ft_memcpy.c\
	   ft_memccpy.c\
	   ft_memmove.c\
	   ft_memchr.c\
	   ft_memcmp.c\
	   ft_strlen.c\
	   ft_strlcpy.c\
	   ft_strlcat.c\
	   ft_strchr.c\
	   ft_strrchr.c\
	   ft_isalpha.c\
	   ft_isdigit.c\
	   ft_isalnum.c\
	   ft_isascii.c\
	   ft_isprint.c\
	   ft_toupper.c\
	   ft_tolower.c\
	   ft_strnstr.c\
	   ft_strncmp.c\
	   ft_atoi.c\
	   ft_strdup.c\
	   ft_calloc.c\
			ft_substr.c\
			ft_strjoin.c\
			ft_putchar_fd.c\
		 	ft_putstr_fd.c\
			ft_putendl_fd.c\
			ft_putnbr_fd.c\
			ft_itoa.c\
			ft_itoa_base.c\
			ft_strmapi.c\
			ft_strtrim.c\
			ft_split.c\
			   ft_lstnew.c\
			   ft_lstadd_front.c\
			   ft_lstsize.c\
			   ft_lstlast.c\
			   ft_lstadd_back.c\
			   ft_lstdelone.c\
			   ft_lstclear.c\
			   ft_lstiter.c\
			   ft_lstmap.c\
			 get_next_line.c\
			 get_next_line_utils.c\
		printf/ft_flags.c\
		printf/ft_print_bx.c\
		printf/ft_print_c.c\
		printf/ft_print_d.c\
		printf/ft_print_d2.c\
		printf/ft_print_p.c\
		printf/ft_print_percent.c\
		printf/ft_print_s.c\
		printf/ft_print_u.c\
		printf/ft_print_x.c\
		printf/ft_utils.c\
		printf/ft_printf.c\




HEADER = libft.h  
OBJS = ${SRCS:.c=.o}
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all:    ${NAME}

$(NAME): ${OBJS}
	@echo "#####################################################################"
	$(AR) rc ${NAME} ${OBJS}

clean:
	@echo "#####################################################################"
	rm -f ${OBJS} ${BONUSOBJ}
fclean: clean
	@echo "#####################################################################"
	rm -f ${NAME}
re: fclean all

.PHONY: all clean fclean re
