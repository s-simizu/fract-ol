/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:12:07 by sshimizu          #+#    #+#             */
/*   Updated: 2023/04/12 16:08:05 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/Xlib.h>
#include <display.h>
#include <draw.h>
#include <event.h>
#include <fractal.h>
#include <mlx.h>
#include <mlx_utils.h>

int	main(void)
{
	t_display	disp;

	init_display(&disp);
	disp.fractal = MANDELBROT;
	mlx_mouse_hook(disp.win, mouse_event, &disp);
	mlx_key_hook(disp.win, key_event, &disp);
	mlx_hook(disp.win, DestroyNotify, 0, close_event, &disp);
	draw(&disp);
	mlx_loop(disp.mlx);
}
