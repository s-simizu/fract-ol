/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:25:08 by sshimizu          #+#    #+#             */
/*   Updated: 2023/04/12 16:06:02 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <display.h>
#include <mandelbrot.h>
#include <mlx.h>
#include <mlx_utils.h>

static void	draw_mandelbrot(t_display *disp)
{
	int	x;
	int	y;
	int	depth;
	int	max_depth;

	max_depth = 100;
	y = 0;
	while (y < disp->height)
	{
		x = 0;
		while (x < disp->width)
		{
			depth = mandelbrot_depth(disp, x, y, max_depth);
			if (depth == max_depth)
				mlx_put_pixel_to_image(&disp->imginfo, x, y, 0x00FFFFFF);
			else
				mlx_put_pixel_to_image(&disp->imginfo, x, y, 0x00000000);
			x++;
		}
		y++;
	}
}

void	draw(t_display *disp)
{
	if (disp->fractal == MANDELBROT)
		draw_mandelbrot(disp);
	mlx_put_image_to_window(disp->mlx, disp->win, disp->imginfo.img, 0, 0);
}
