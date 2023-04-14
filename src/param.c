/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 23:46:54 by sshimizu          #+#    #+#             */
/*   Updated: 2023/04/15 07:22:55 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "draw.h"

#define ADJUSTMENT_AMOUNT 0.01

void	julia_re_plus(t_display *disp)
{
	disp->julia_param.re += ADJUSTMENT_AMOUNT * disp->zoom_level;
	draw(disp);
}

void	julia_re_minus(t_display *disp)
{
	disp->julia_param.re -= ADJUSTMENT_AMOUNT * disp->zoom_level;
	draw(disp);
}

void	julia_im_plus(t_display *disp)
{
	disp->julia_param.im += ADJUSTMENT_AMOUNT * disp->zoom_level;
	draw(disp);
}

void	julia_im_minus(t_display *disp)
{
	disp->julia_param.im -= ADJUSTMENT_AMOUNT * disp->zoom_level;
	draw(disp);
}
