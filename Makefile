# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/14 10:46:37 by sshimizu          #+#    #+#              #
#    Updated: 2023/04/13 14:11:35 by sshimizu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -Iinclude -Ilibft -Imlx
LIB_DIR = -Llibft -Lmlx
LIB = -l$(MLX_LIB) -lft -lm -lX11 -lXext
FRAMEWORK = -framework OpenGL -framework AppKit

MLX_DIR = mlx/
MLX_LINUX = mlx_Linux
mac: MLX_MAC = mlx_Darwin
mac: X11_MAC_INCLUDE = /usr/X11/include
mac: X11_MAC_LIB_DIR = /usr/X11/lib

ifdef MLX_MAC
MLX_LIB = $(MLX_MAC)
INCLUDE += -I$(X11_MAC_INCLUDE)
LIB_DIR += -L$(X11_MAC_LIB_DIR)
LIB += $(FRAMEWORK)
else
MLX_LIB = $(MLX_LINUX)
INCLUDE += -I/usr/include
LIB_DIR += -L/usr/lib
endif

MLX = $(LIB_PREFIX)$(MLX_LIB)$(LIB_SUFFIX)
LIB_SUFFIX = .a
LIB_PREFIX = lib

LIBFT_DIR = libft/
LIBFT = libft.a

SRCS = main.c arg.c color.c complex.c depth.c display.c draw.c event.c move.c notify.c param.c zoom.c
OBJS = $(SRCS:.c=.o)

VPATH = libft include mlx src

all: $(NAME)

bonus: all

mac: all

$(NAME): $(OBJS) $(MLX) $(LIBFT)
	$(CC) $(CFLAGS) $(LIB_DIR) $(OBJS) $(LIB) -o $@

$(MLX):
	$(MAKE) -C $(MLX_DIR)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -O3 -c $< -o $@

arg.c: color.h display.h fractal.h libft.h
color.c: color.h display.h draw.h
complex.c: ft_complex.h
depth.c: ft_complex.h
display.c: arg.h display.h ft_complex.h libft.h mlx.h
draw.c: color.h depth.h display.h fractal.h mlx.h
event.c: color.h display.h move.h param.h zoom.h
main.c: arg.h display.h draw.h event.h fractal.h mlx.h
move.c: display.h draw.h
notify.c: display.h draw.h
zoom.c: draw.h ft_complex.h

clean:
	$(MAKE) clean -C $(MLX_DIR)
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus mac
