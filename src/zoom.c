/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:01:40 by sshimizu          #+#    #+#             */
/*   Updated: 2023/04/12 13:47:20 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <draw.h>
#include <ft_complex.h>

#define ZOOM_FACTOR 0.9
#define DEFAULT_RE_RANGE 4.0
#define DEFAULT_IM_RANGE 2.4

static t_complex	point_to_complex(t_display *disp, int x, int y)
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

void	zoom_in(t_display *disp, int x, int y)
{
	t_complex	offset;
	t_complex	complex_before_zoom;
	t_complex	complex_after_zoom;

	complex_before_zoom = point_to_complex(disp, x, y);
	disp->zoom_level *= ZOOM_FACTOR;
	complex_after_zoom = point_to_complex(disp, x, y);
	offset = complex_sub(complex_after_zoom, complex_before_zoom);
	disp->center = complex_sub(disp->center, offset);
	draw(disp);
}

void	zoom_out(t_display *disp, int x, int y)
{
	t_complex	offset;
	t_complex	complex_before_zoom;
	t_complex	complex_after_zoom;

	complex_before_zoom = point_to_complex(disp, x, y);
	disp->zoom_level /= ZOOM_FACTOR;
	complex_after_zoom = point_to_complex(disp, x, y);
	offset = complex_sub(complex_after_zoom, complex_before_zoom);
	disp->center = complex_sub(disp->center, offset);
	draw(disp);
}
