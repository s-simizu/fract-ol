/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:51:38 by sshimizu          #+#    #+#             */
/*   Updated: 2023/04/12 19:59:36 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_complex.h>
#include <math.h>

int	calc_depth(t_complex z, t_complex c, int max_depth)
{
	int	depth;

	depth = 0;
	while (depth < max_depth)
	{
		z = complex_sum(complex_mul(z, z), c);
		if (complex_abs(z) > 2.0)
			return (depth);
		depth++;
	}
	return (depth);
}

int	calc_depth_burning_ship(t_complex z, t_complex c, int max_depth)
{
	int	depth;

	depth = 0;
	while (depth < max_depth)
	{
		z.re = fabs(z.re);
		z.im = fabs(z.im);
		z = complex_sum(complex_mul(z, z), c);
		if (complex_abs(z) > 2.0)
			return (depth);
		depth++;
	}
	return (depth);
}
