/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:12:07 by sshimizu          #+#    #+#             */
/*   Updated: 2023/04/15 07:22:11 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg.h"
#include "display.h"
#include "draw.h"
#include "event.h"
#include "fractal.h"
#include "mlx.h"
#include "notify.h"
#include <X11/Xlib.h>

int	main(int argc, char *argv[])
{
	t_display	disp;

	if (argc != 3)
	{
		print_usage();
		return (0);
	}
	init_display(&disp, argv[2]);
	set_fractal_info(&disp, argv[1]);
	mlx_mouse_hook(disp.win, mouse_event, &disp);
	mlx_key_hook(disp.win, key_event, &disp);
	mlx_hook(disp.win, DestroyNotify, 0, destroy_notify, &disp);
	mlx_hook(disp.win, MapNotify, 0xFFFFFF, map_notify, &disp);
	draw(&disp);
	mlx_loop(disp.mlx);
}
