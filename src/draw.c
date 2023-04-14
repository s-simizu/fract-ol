/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:25:08 by sshimizu          #+#    #+#             */
/*   Updated: 2023/04/15 07:21:20 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "depth.h"
#include "display.h"
#include "fractal.h"
#include "mlx.h"
#include <limits.h>

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

static void	put_pixel_to_image(t_imginfo *imginfo, int x, int y,
		unsigned int color)
{
	int		offset;
	char	*dst;

	offset = y * imginfo->size_line + x * (imginfo->bits_per_pixel / CHAR_BIT);
	dst = imginfo->addr + offset;
	*(unsigned int *)dst = color;
}

static void	draw_pixel(t_display *disp, int x, int y)
{
	t_complex		z;
	t_complex		c;
	unsigned int	color;

	if (disp->fractal == JULIA)
	{
		z = point_to_complex(disp, x, y);
		c = disp->julia_param;
		color = get_color(disp, depth(z, c, disp->max_depth), disp->max_depth);
	}
	else if (disp->fractal == MANDELBROT)
	{
		z = (t_complex){0, 0};
		c = point_to_complex(disp, x, y);
		color = get_color(disp, depth(z, c, disp->max_depth), disp->max_depth);
	}
	else
	{
		z = (t_complex){0, 0};
		c = point_to_complex(disp, x, y);
		color = get_color(disp, depth_burning_ship(z, c, disp->max_depth),
				disp->max_depth);
	}
	put_pixel_to_image(&disp->imginfo, x, y, color);
}

static void	put_usage(t_display *disp)
{
	int	margin;

	margin = disp->height / 20;
	mlx_string_put(disp->mlx, disp->win, margin, disp->height - margin * 3,
			WHITE, "arrows : move");
	mlx_string_put(disp->mlx, disp->win, margin, disp->height - margin * 2,
			WHITE, "r,g,b  : change color");
	mlx_string_put(disp->mlx, disp->win, margin, disp->height - margin, WHITE,
			"w,a,s,d: change julia parameter.");
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
	put_usage(disp);
}
