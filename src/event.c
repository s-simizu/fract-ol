/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:56:46 by sshimizu          #+#    #+#             */
/*   Updated: 2023/04/13 00:38:59 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <color.h>
#include <display.h>
#include <move.h>
#include <param.h>
#include <zoom.h>

int	mouse_event(int button, int x, int y, t_display *disp)
{
	if (button == Button4)
		zoom_in(disp, x, y);
	else if (button == Button5)
		zoom_out(disp, x, y);
	return (0);
}

void	set_move(int keycode, t_display *disp)
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
}

void	set_change_param(int keycode, t_display *disp)
{
	if (keycode == XK_r)
		change_red(disp);
	else if (keycode == XK_g)
		change_green(disp);
	else if (keycode == XK_b)
		change_blue(disp);
	else if (keycode == XK_w)
		julia_im_minus(disp);
	else if (keycode == XK_a)
		julia_re_minus(disp);
	else if (keycode == XK_s)
		julia_im_plus(disp);
	else if (keycode == XK_d)
		julia_re_plus(disp);
}

int	key_event(int keycode, t_display *disp)
{
	set_move(keycode, disp);
	set_change_param(keycode, disp);
	return (0);
}

int	close_event(t_display *disp)
{
	destroy_display(disp);
	return (0);
}
