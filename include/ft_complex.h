/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:25:14 by sshimizu          #+#    #+#             */
/*   Updated: 2023/03/22 22:21:12 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COMPLEX_H
# define FT_COMPLEX_H

typedef struct s_complex
{
	double	re;
	double	im;
}			t_complex;

t_complex	create_complex(double r, double i);
t_complex	sum_complex(t_complex c1, t_complex c2);
t_complex	multiply_complex(t_complex c1, t_complex c2);
t_complex	square_complex(t_complex c);
double		abs_complex(t_complex c);

#endif