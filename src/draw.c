/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:25:08 by sshimizu          #+#    #+#             */
/*   Updated: 2023/04/12 21:35:13 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <calc.h>
#include <color.h>
#include <display.h>
#include <fractal.h>
#include <mlx.h>
#include <mlx_utils.h>

#define DEFAULT_RE_RANGE 4.0
#define DEFAULT_IM_RANGE 2.4

t_complex	point_to_complex(t_display *disp, int x, int y)
{
	double	re;
	double	im;
	double	re_range;
	double	im_range;

	re_range = DEFAULT_RE_RANGE * disp->zoom_level;
	im_range = DEFAULT_IM_RANGE * disp->zoom_level;
	re = ((double)x / disp->width) * re_range - re_range / 2 + disp->center.re;
	im = ((double)y / disp->height) * im_range - im_range / 2 + disp->center.im;
	return ((t_complex){re, im});
}

static void	draw_pixel(t_display *disp, int x, int y)
{
	t_complex	z;
	t_complex	c;
	t_color		color;

	color = 0x00000000;
	if (disp->fractal == JULIA)
	{
		z = point_to_complex(disp, x, y);
		c = disp->julia_param;
		color = get_color(calc_depth(z, c, disp->max_depth), disp->max_depth);
	}
	else if (disp->fractal == MANDELBROT)
	{
		z = (t_complex){0, 0};
		c = point_to_complex(disp, x, y);
		color = get_color(calc_depth(z, c, disp->max_depth), disp->max_depth);
	}
	else if (disp->fractal == BURNING)
	{
		z = (t_complex){0, 0};
		c = point_to_complex(disp, x, y);
		color = get_color(calc_depth_burning_ship(z, c, disp->max_depth),
				disp->max_depth);
	}
	mlx_put_pixel_to_image(&disp->imginfo, x, y, color);
}

void	draw(t_display *disp)
{
	int	x;
	int	y;

	y = 0;
	while (y < disp->height)
	{
		x = 0;
		while (x < disp->width)
		{
			draw_pixel(disp, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(disp->mlx, disp->win, disp->imginfo.img, 0, 0);
}
