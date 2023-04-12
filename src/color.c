/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:36:38 by sshimizu          #+#    #+#             */
/*   Updated: 2023/04/13 01:39:38 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <color.h>
#include <display.h>
#include <draw.h>
#include <math.h>

static unsigned int	change_brightness(unsigned int color, double depth_ratio)
{
	unsigned int	rgb[3];

	if (depth_ratio > 1.0)
		depth_ratio = 1.0;
	rgb[0] = (color >> 16) * depth_ratio;
	rgb[1] = ((color >> 8) & 0xFF) * depth_ratio;
	rgb[2] = (color & 0xFF) * depth_ratio;
	return (rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}

unsigned int	get_color(t_display *disp, int depth, int max_depth)
{
	double	depth_ratio;

	depth_ratio = log(depth) / log(max_depth);
	if (depth_ratio == 1.0 || depth_ratio == 0)
		return (BLACK);
	return (change_brightness(disp->color, depth_ratio));
}

void	change_red(t_display *disp)
{
	unsigned int	red;

	red = disp->color >> 16;
	if (red == 0x00)
		disp->color |= 0x00800000;
	else if (red == 0x80)
		disp->color |= 0x00FF0000;
	else if (red == 0xFF)
		disp->color &= 0x0000FFFF;
	draw(disp);
}

void	change_green(t_display *disp)
{
	unsigned int	green;

	green = (disp->color >> 8) & 0xFF;
	if (green == 0x00)
		disp->color |= 0x00008000;
	else if (green == 0x80)
		disp->color |= 0x0000FF00;
	else if (green == 0xFF)
		disp->color &= 0x00FF00FF;
	draw(disp);
}

void	change_blue(t_display *disp)
{
	unsigned int	blue;

	blue = disp->color & 0xFF;
	if (blue == 0x00)
		disp->color |= 0x00000080;
	else if (blue == 0x80)
		disp->color |= 0x000000FF;
	else if (blue == 0xFF)
		disp->color &= 0x00FFFF00;
	draw(disp);
}
