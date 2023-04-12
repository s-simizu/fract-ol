# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/14 10:46:37 by sshimizu          #+#    #+#              #
#    Updated: 2023/04/12 21:00:09 by sshimizu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror $(INCLUDE)
INCLUDE = -Iinclude -Ilibft -Imlx -I/usr/X11/include
LIB = -Llibft -lft -lm -Lmlx -lmlx_Darwin -L/usr/X11/lib -lX11 -lXext
FLAMEWORK = -framework OpenGL -framework AppKit
LIBFT = libft.a

SRCS = calc.c color.c complex.c display.c draw.c event.c main.c mlx_utils.c move.c zoom.c
OBJS = $(SRCS:.c=.o)

VPATH = libft include mlx src

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(LIB) $(FLAMEWORK) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

complex.c: ft_complex.h
display.c: display.h ft_complex.h libft.h mlx.h
draw.c: calc.c color.h display.h fractal.h mlx.h mlx_utils.h
event.c: display.h move.h zoom.h
main.c: display.h event.h fractal.h mlx.h mlx_utils.h
mandelbrot.c: ft_complex.h mlx_utils.h
move.c: display.h draw.h
zoom.c: draw.h ft_complex.h

test: test.o
	$(CC) $^ -Lmlx -lmlx_Darwin -L/usr/X11/lib -lX11 -lXext -framework OpenGL -framework AppKit -o $@

testm: test_mandelbrot.o mlx_utils.o mandelbrot.o complex.o display.o $(LIBFT)
	$(CC) $^ -Lmlx -lmlx_Darwin -L/usr/X11/lib -lX11 -lXext -Llibft -lft -framework OpenGL -framework AppKit -o $@

$(LIBFT):
	$(MAKE) -C libft/

clean:
	$(MAKE) fclean -C libft/
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
