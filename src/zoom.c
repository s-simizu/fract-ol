/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:01:40 by sshimizu          #+#    #+#             */
/*   Updated: 2023/04/12 21:31:48 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <draw.h>
#include <ft_complex.h>

#define ZOOM_FACTOR 0.9

void	zoom_in(t_display *disp, int x, int y)
{
	t_complex	offset;
	t_complex	complex_before_zoom;
	t_complex	complex_after_zoom;

	complex_before_zoom = point_to_complex(disp, x, y);
	disp->zoom_level *= ZOOM_FACTOR;
	disp->max_depth++;
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
	disp->max_depth--;
	complex_after_zoom = point_to_complex(disp, x, y);
	offset = complex_sub(complex_after_zoom, complex_before_zoom);
	disp->center = complex_sub(disp->center, offset);
	draw(disp);
}
