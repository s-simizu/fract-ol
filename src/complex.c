/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:26:58 by sshimizu          #+#    #+#             */
/*   Updated: 2023/04/12 10:32:16 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_complex.h>
#include <math.h>

t_complex	complex_sum(t_complex c1, t_complex c2)
{
	return ((t_complex){c1.re + c2.re, c1.im + c2.im});
}

t_complex	complex_sub(t_complex c1, t_complex c2)
{
	return ((t_complex){c1.re - c2.re, c1.im - c2.im});
}

t_complex	complex_mul(t_complex c1, t_complex c2)
{
	t_complex	result;

	result.re = c1.re * c2.re - (c1.im * c2.im);
	result.im = c1.re * c2.im + c1.im * c2.re;
	return (result);
}

t_complex	complex_pow(t_complex c, unsigned int exp)
{
	t_complex		result;
	unsigned int	n;

	if (exp == 0)
		return ((t_complex){1, 0});
	result = c;
	n = 1;
	while (n < exp)
	{
		result = complex_mul(result, c);
		n++;
	}
	return (result);
}

double	complex_abs(t_complex c)
{
	return (sqrt(c.re * c.re + c.im * c.im));
}
