/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelblot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 22:19:47 by sshimizu          #+#    #+#             */
/*   Updated: 2023/03/22 22:21:44 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_complex.h>

int	mandelblot(t_complex c, int n)
{
	t_complex	z;
	int			repeat;

	repeat = 0;
	z = c;
	while (repeat < n)
	{
		z = sum_complex(square_complex(z), c);
		if (abs_complex(z) > 2.0)
			return (repeat);
		repeat++;
	}
	return (repeat);
}
