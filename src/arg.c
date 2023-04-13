/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 00:11:21 by sshimizu          #+#    #+#             */
/*   Updated: 2023/04/13 10:43:40 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <color.h>
#include <display.h>
#include <fractal.h>
#include <libft.h>

#define INITIAL_COLOR RED

#define INITIAL_JULIA_PARAM_RE -0.3
#define INITIAL_JULIA_PARAM_IM -0.63

#define JULIA_CENTER_RE 0.0;
#define JULIA_CENTER_IM 0.0;
#define MANDELBROT_CENTER_RE -0.5
#define MANDELBROT_CENTER_IM 0.0
#define BURNING_CENTER_RE -0.4
#define BURNING_CENTER_IM -0.4

void	print_usage(void)
{
	ft_printf("usage: fractol [FRACTAL_TYPE] [DISPLAY_SIZE]\n");
	ft_printf("  FRACTAL_TYPE\n");
	ft_printf("    j: julia set\n");
	ft_printf("    m: mandelbrot set\n");
	ft_printf("    b: burning ship\n");
	ft_printf("  DISPLAY_SIZE\n");
	ft_printf("    s: 480 x 272\n");
	ft_printf("    m: 800 x 480\n");
	ft_printf("    l: 1280 x 720\n");
}

static void	set_julia_info(t_display *disp)
{
	disp->fractal = JULIA;
	disp->julia_param.re = INITIAL_JULIA_PARAM_RE;
	disp->julia_param.im = INITIAL_JULIA_PARAM_IM;
	disp->center.re = JULIA_CENTER_RE;
	disp->center.im = JULIA_CENTER_IM;
}

static void	set_mandelbrot_info(t_display *disp)
{
	disp->fractal = MANDELBROT;
	disp->center.re = MANDELBROT_CENTER_RE;
	disp->center.im = MANDELBROT_CENTER_IM;
}

static void	set_burning_ship_info(t_display *disp)
{
	disp->fractal = BURNING;
	disp->center.re = BURNING_CENTER_RE;
	disp->center.im = BURNING_CENTER_IM;
}

void	set_fractal_info(t_display *disp, char *str)
{
	disp->color = INITIAL_COLOR;
	if (ft_strncmp(str, "j", 2) == 0)
		set_julia_info(disp);
	else if (ft_strncmp(str, "m", 2) == 0)
		set_mandelbrot_info(disp);
	else if (ft_strncmp(str, "b", 2) == 0)
		set_burning_ship_info(disp);
	else
	{
		print_usage();
		destroy_display(disp);
	}
}
