# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/14 10:46:37 by sshimizu          #+#    #+#              #
#    Updated: 2023/04/11 02:07:39 by sshimizu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror $(INCLUDE)
INCLUDE = -Iinclude -Imlx -I/usr/X11/include
LIB = -lm -Lmlx -lmlx_Darwin -L/usr/X11/lib -lX11 -lXext -Llibft -lft
FLAMEWORK = -framework OpenGL -framework AppKit
LIBFT = libft.a
VPATH = libft src include

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -Iinclude -Ilibft -I/usr/X11/include -c $< -o $@

test: test.o
	$(CC) $^ -Lmlx -lmlx_Darwin -L/usr/X11/lib -lX11 -lXext -framework OpenGL -framework AppKit -o $@

testm: test_mandelbrot.o mlx_utils.o mandelbrot.o complex.o display.o $(LIBFT)
	$(CC) $^ -Lmlx -lmlx_Darwin -L/usr/X11/lib -lX11 -lXext -Llibft -lft -framework OpenGL -framework AppKit -o $@

$(LIBFT):
	$(MAKE) -C libft/