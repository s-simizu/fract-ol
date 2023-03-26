# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/14 10:46:37 by sshimizu          #+#    #+#              #
#    Updated: 2023/03/25 15:07:46 by sshimizu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -Imlx -I/usr/X11/include
LIB = -Lmlx -lmlx_Darwin -L/usr/X11/lib -lX11 -lXext
FLAMEWORK = -framework OpenGL -framework AppKit

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -Iinclude -I/usr/X11/include -c $< -o $@

test: test.o
	$(CC) $^ -Lmlx -lmlx_Darwin -L/usr/X11/lib -lX11 -lXext -framework OpenGL -framework AppKit -o $@

m: test_mandelbrot.o mlx_utils.o mandelbrot.o complex.o
	$(CC) $^ -Lmlx -lmlx_Darwin -L/usr/X11/lib -lX11 -lXext -framework OpenGL -framework AppKit -o $@
