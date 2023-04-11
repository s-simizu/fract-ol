/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 22:26:59 by sshimizu          #+#    #+#             */
/*   Updated: 2023/03/27 14:08:42 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <mlx_utils.h>

void	mlx_put_pixel_to_image(t_imginfo *imginfo, int x, int y,
		unsigned int color)
{
	int		offset;
	char	*dst;

	offset = y * imginfo->size_line + x * (imginfo->bits_per_pixel / CHAR_BIT);
	dst = imginfo->addr + offset;
	*(unsigned int *)dst = color;
}
