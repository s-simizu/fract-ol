/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 19:09:00 by sshimizu          #+#    #+#             */
/*   Updated: 2023/03/22 22:22:04 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_complex.h>
#include <stdio.h>

void	print_complex(t_complex c)
{
	printf("r: %lf i: %lf\n", c.re, c.im);
}

int	main(void)
{
	t_complex	c1;
	t_complex	c2;

	c1 = create_complex(3.5, 5.1);
	c2 = create_complex(3.5, 10);
	print_complex(multiply_complex(c1, c2));
	// printf("%lf\n", abs_complex(c1));
}
