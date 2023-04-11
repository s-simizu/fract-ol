/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 22:19:47 by sshimizu          #+#    #+#             */
/*   Updated: 2023/04/11 11:08:11 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_complex.h>
#include <mlx_utils.h>
#include <stdbool.h>

#define DEFAULT_RE_RANGE 4.0
#define DEFAULT_IM_RANGE 2.4

static bool	is_convergent(t_complex c)
{
	return (c.re >= -0.5 && c.re <= 0.2 && c.im >= -0.5 && c.im <= 0.5);
}

static int	escape_count(t_complex c, int max_loop)
{
	t_complex	z;
	int			loop;

	if (is_convergent(c))
		return (max_loop);
	z = (t_complex){0, 0};
	loop = 0;
	while (loop < max_loop)
	{
		z = complex_sum(complex_pow(z, 2), c);
		if (complex_abs(z) > 2.0)
			return (loop);
		loop++;
	}
	return (loop);
}

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

int	mandelbrot_depth(t_display *disp, int x, int y, int max_depth)
{
	t_complex	c;

	c = point_to_complex(disp, x, y);
	return (escape_count(c, max_depth));
}
