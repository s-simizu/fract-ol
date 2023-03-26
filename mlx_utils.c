/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 22:26:59 by sshimizu          #+#    #+#             */
/*   Updated: 2023/03/26 19:34:27 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <mlx.h>
#include <mlx_utils.h>
#include <stddef.h>
#include <stdlib.h>

#define DEFAULT_WIDTH 1280
#define DEFAULT_HEIGHT 720

static t_display	init_display(void)
{
	t_display	disp;

	disp.mlx = NULL;
	disp.win = NULL;
	disp.imginfo.img = NULL;
	disp.imginfo.addr = NULL;
	disp.width = 0;
	disp.height = 0;
	return (disp);
}

void	free_display(t_display *disp)
{
	free(disp->mlx);
	free(disp->win);
	free(disp->imginfo.addr);
	free(disp->imginfo.img);
	exit(1);
}

t_display	new_display(int width, int height)
{
	t_display	disp;

	disp = init_display();
	disp.mlx = mlx_init();
	if (!disp.mlx)
		free_display(&disp);
	disp.win = mlx_new_window(disp.mlx, width, height, "fractal");
	if (!disp.win)
		free_display(&disp);
	disp.imginfo.img = mlx_new_image(disp.mlx, width, height);
	if (!disp.imginfo.img)
		free_display(&disp);
	disp.imginfo.addr = mlx_get_data_addr(disp.imginfo.img,
			&disp.imginfo.bits_per_pixel, &disp.imginfo.size_line,
			&disp.imginfo.endian);
	disp.width = width;
	disp.height = height;
	return (disp);
}

void	mlx_put_pixel_to_image(t_imginfo *imginfo, int x, int y,
		unsigned int color)
{
	int		offset;
	char	*dst;

	offset = y * imginfo->size_line + x * (imginfo->bits_per_pixel / CHAR_BIT);
	dst = imginfo->addr + offset;
	*(unsigned int *)dst = color;
}
