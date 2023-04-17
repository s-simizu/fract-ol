/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 10:59:02 by sshimizu          #+#    #+#             */
/*   Updated: 2023/04/18 00:40:13 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "draw.h"

#define DEFAULT_MOVE_AMOUNT 0.25

void	move_up(t_display *disp)
{
	disp->center.im -= DEFAULT_MOVE_AMOUNT * disp->zoom_level;
	draw(disp);
}

void	move_down(t_display *disp)
{
	disp->center.im += DEFAULT_MOVE_AMOUNT * disp->zoom_level;
	draw(disp);
}

void	move_left(t_display *disp)
{
	disp->center.re -= DEFAULT_MOVE_AMOUNT * disp->zoom_level;
	draw(disp);
}

void	move_right(t_display *disp)
{
	disp->center.re += DEFAULT_MOVE_AMOUNT * disp->zoom_level;
	draw(disp);
}
