/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:56:46 by sshimizu          #+#    #+#             */
/*   Updated: 2023/04/12 16:06:45 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <display.h>
#include <move.h>
#include <zoom.h>

int	mouse_event(int button, int x, int y, t_display *disp)
{
	if (button == Button4)
		zoom_in(disp, x, y);
	else if (button == Button5)
		zoom_out(disp, x, y);
	return (0);
}

int	key_event(int keycode, t_display *disp)
{
	if (keycode == XK_Up)
		move_up(disp);
	else if (keycode == XK_Down)
		move_down(disp);
	else if (keycode == XK_Left)
		move_left(disp);
	else if (keycode == XK_Right)
		move_right(disp);
	else if (keycode == XK_Escape)
		destroy_display(disp);
	return (0);
}

int	close_event(t_display *disp)
{
	destroy_display(disp);
	return (0);
}
