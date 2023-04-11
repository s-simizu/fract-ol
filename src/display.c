/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 20:47:39 by sshimizu          #+#    #+#             */
/*   Updated: 2023/04/11 11:13:41 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <display.h>
#include <ft_complex.h>
#include <libft.h>
#include <mlx.h>
#include <stdlib.h>

#define DEFAULT_CENTER_RE -0.5
#define DEFAULT_CENTER_IM 0.0

void	destroy_display(t_display *disp)
{
	if (!disp || !disp->mlx)
		return ;
	if (disp->imginfo.img)
		mlx_destroy_image(disp->mlx, disp->imginfo.img);
	if (disp->win)
		mlx_destroy_window(disp->mlx, disp->win);
	mlx_destroy_display(disp->mlx);
	exit(1);
}

void	init_display(t_display *disp, int width, int height)
{
	ft_bzero(disp, sizeof(t_display));
	disp->mlx = mlx_init();
	if (!disp->mlx)
		destroy_display(disp);
	disp->win = mlx_new_window(disp->mlx, width, height, "fractal");
	if (!disp->win)
		destroy_display(disp);
	disp->imginfo.img = mlx_new_image(disp->mlx, width, height);
	if (!disp->imginfo.img)
		destroy_display(disp);
	disp->imginfo.addr = mlx_get_data_addr(disp->imginfo.img,
			&disp->imginfo.bits_per_pixel, &disp->imginfo.size_line,
			&disp->imginfo.endian);
	disp->width = width;
	disp->height = height;
	disp->zoom_level = 1.0;
	disp->center = (t_complex){DEFAULT_CENTER_RE, DEFAULT_CENTER_IM};
}
