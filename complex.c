/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:26:58 by sshimizu          #+#    #+#             */
/*   Updated: 2023/03/22 22:21:25 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_complex.h>
#include <math.h>

t_complex	create_complex(double r, double i)
{
	t_complex	c;

	c.re = r;
	c.im = i;
	return (c);
}

t_complex	sum_complex(t_complex c1, t_complex c2)
{
	t_complex	result;

	result.re = c1.re + c2.re;
	result.im = c1.im + c2.im;
	return (result);
}

t_complex	multiply_complex(t_complex c1, t_complex c2)
{
	t_complex	result;

	result.re = c1.re * c2.re - (c1.im * c2.im);
	result.im = c1.re * c2.im + c1.im * c2.re;
	return (result);
}

t_complex	square_complex(t_complex c)
{
	return (multiply_complex(c, c));
}

double	abs_complex(t_complex c)
{
	return (sqrt(c.re * c.re + c.im * c.im));
}


