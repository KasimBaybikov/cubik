/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 17:48:01 by rvernon           #+#    #+#             */
/*   Updated: 2020/12/30 23:37:37 by kasimbayb        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# define BUFFER_SIZE 16

int				get_next_line(int fd, char **line);
int				ft_strlen_gnl(char *s);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *src);
char			*ft_strjoin_gnl(char *s1, char *s2);
int				find_n(char *cache);
char			*ft_before_dup(int len, char *cache);
char			*before_n(char *cache);
char			*after_n(char *cache);

#endif
