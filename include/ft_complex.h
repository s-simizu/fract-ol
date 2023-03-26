/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:25:14 by sshimizu          #+#    #+#             */
/*   Updated: 2023/03/26 20:38:41 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COMPLEX_H
# define FT_COMPLEX_H

typedef struct s_complex
{
	double	re;
	double	im;
}			t_complex;

t_complex	new_complex(double re, double im);
t_complex	complex_sum(t_complex c1, t_complex c2);
t_complex	complex_multiply(t_complex c1, t_complex c2);
t_complex	complex_square(t_complex c);
double		complex_abs(t_complex c);

#endif