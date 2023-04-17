/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 20:47:39 by sshimizu          #+#    #+#             */
/*   Updated: 2023/04/18 00:26:29 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg.h"
#include "display.h"
#include "ft_complex.h"
#include "libft.h"
#include "mlx.h"
#include <stdlib.h>

#define S_WIDTH 480
#define S_HEIGHT 272
#define M_WIDTH 800
#define M_HEIGHT 480
#define L_WIDTH 1280
#define L_HEIGHT 720

#define INITIAL_MAX_DEPTH 100
#define INITIAL_ZOOM_LEVEL 1.0

void	destroy_display(t_display *disp)
{
	if (!disp || !disp->mlx)
		exit(1);
	if (disp->imginfo.img)
		mlx_destroy_image(disp->mlx, disp->imginfo.img);
	if (disp->win)
		mlx_destroy_window(disp->mlx, disp->win);
	mlx_destroy_display(disp->mlx);
	exit(0);
}

static void	set_display_size(t_display *disp, char *disp_size)
{
	if (ft_strncmp(disp_size, "s", 2) == 0)
	{
		disp->width = S_WIDTH;
		disp->height = S_HEIGHT;
	}
	else if (ft_strncmp(disp_size, "m", 2) == 0)
	{
		disp->width = M_WIDTH;
		disp->height = M_HEIGHT;
	}
	else if (ft_strncmp(disp_size, "l", 2) == 0)
	{
		disp->width = L_WIDTH;
		disp->height = L_HEIGHT;
	}
	else
	{
		print_usage();
		destroy_display(disp);
	}
}

void	init_display(t_display *disp, char *disp_size)
{
	ft_bzero(disp, sizeof(t_display));
	set_display_size(disp, disp_size);
	disp->mlx = mlx_init();
	if (!disp->mlx)
		destroy_display(disp);
	disp->win = mlx_new_window(disp->mlx, disp->width, disp->height,
			"fract-ol");
	if (!disp->win)
		destroy_display(disp);
	disp->imginfo.img = mlx_new_image(disp->mlx, disp->width, disp->height);
	if (!disp->imginfo.img)
		destroy_display(disp);
	disp->imginfo.addr = mlx_get_data_addr(disp->imginfo.img,
			&disp->imginfo.bits_per_pixel,
			&disp->imginfo.size_line,
			&disp->imginfo.endian);
	disp->max_depth = INITIAL_MAX_DEPTH;
	disp->zoom_level = INITIAL_ZOOM_LEVEL;
}
