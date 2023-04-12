# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/14 10:46:37 by sshimizu          #+#    #+#              #
#    Updated: 2023/04/13 02:07:22 by sshimizu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror $(INCLUDE)
INCLUDE = -Iinclude -Ilibft -Imlx -I/usr/X11/include
LIB = -Llibft -lft -lm -Lmlx -lmlx_Darwin -L/usr/X11/lib -lX11 -lXext
FLAMEWORK = -framework OpenGL -framework AppKit
MLX_DIR = mlx/
MLX = libmlx_Darwin.a
LIBFT_DIR = libft/
LIBFT = libft.a

SRCS = arg.c color.c complex.c depth.c display.c draw.c event.c main.c move.c param.c zoom.c
OBJS = $(SRCS:.c=.o)

VPATH = libft include mlx src

all: $(NAME)

$(NAME): $(OBJS) $(MLX) $(LIBFT)
	$(CC) $(CFLAGS) $(LIB) $(FLAMEWORK) $(OBJS) $(LIBFT_DIR)$(LIBFT) -o $@

$(MLX):
	$(MAKE) -C $(MLX_DIR)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

arg.c: display.h fractal.h libft.h
color.c: color.h display.h draw.h
complex.c: ft_complex.h
depth.c: ft_complex.h
display.c: display.h ft_complex.h libft.h mlx.h
draw.c: color.h depth.h display.h fractal.h mlx.h
event.c: color.h display.h move.h param.h zoom.h
main.c: arg.h display.h draw.h event.h fractal.h mlx.h
move.c: display.h draw.h
zoom.c: draw.h ft_complex.h

clean:
	$(MAKE) clean -C $(MLX_DIR)
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
