# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/14 10:46:37 by sshimizu          #+#    #+#              #
#    Updated: 2023/04/14 14:01:56 by sshimizu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror -MMD -MP
INCLUDE = -Iinclude -Ilibft -Imlx
LIB_DIR = -Llibft -Lmlx
LIB = -l$(MLX_LIB) -lft -lm -lX11 -lXext
FRAMEWORK = -framework OpenGL -framework AppKit

UNAME = $(shell uname)

ifeq ($(UNAME),Darwin)
MLX_LIB := mlx_Darwin
INCLUDE += -I/usr/X11/include
LIB_DIR += -L/usr/X11/lib
LIB += $(FRAMEWORK)
else
MLX_LIB := mlx_Linux
endif

MLX_DIR = mlx/
MLX = $(MLX_DIR)$(LIB_PREFIX)$(MLX_LIB)$(LIB_SUFFIX)
LIB_SUFFIX = .a
LIB_PREFIX = lib

LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a

SRCS = src/main.c src/arg.c src/color.c src/complex.c \
 src/depth.c src/display.c src/draw.c src/event.c \
 src/move.c src/notify.c src/param.c src/zoom.c
OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)

all: $(NAME)

bonus: all

$(NAME): $(OBJS) $(MLX) $(LIBFT)
	$(CC) $(CFLAGS) $(LIB_DIR) $(OBJS) $(LIB) -o $@

$(MLX):
	$(MAKE) -C $(MLX_DIR)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

-include $(DEPS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -O3 -c $< -o $@

clean:
	$(MAKE) clean -C $(MLX_DIR)
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(OBJS) $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
