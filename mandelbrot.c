/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 22:19:47 by sshimizu          #+#    #+#             */
/*   Updated: 2023/03/26 20:40:25 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_complex.h>
#include <mlx_utils.h>
#include <stdbool.h>

#define RE_RANGE 4.0
#define IM_RANGE 2.4
#define RE_OFFSET 2.5
#define IM_OFFSET 1.2

static bool	is_convergent(t_complex c)
{
	return (c.re >= -0.5 && c.re <= 0.2 && c.im >= -0.5 && c.im <= 0.5);
}

static int	escape_count(t_complex c, int max_count)
{
	t_complex	z;
	int			count;

	if (is_convergent(c))
		return (max_count);
	z = new_complex(0, 0);
	count = 0;
	while (count < max_count)
	{
		z = complex_sum(complex_square(z), c);
		if (complex_abs(z) > 2.0)
			return (count);
		count++;
	}
	return (count);
}

int	mandelbrot_depth(t_display disp, int x, int y, int max_depth)
{
	double	re;
	double	im;

	re = ((double)x / disp.width) * RE_RANGE - RE_OFFSET;
	im = ((double)y / disp.height) * IM_RANGE - IM_OFFSET;
	return (escape_count(new_complex(re, im), max_depth));
}
