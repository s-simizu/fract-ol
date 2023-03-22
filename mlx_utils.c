/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 22:26:59 by sshimizu          #+#    #+#             */
/*   Updated: 2023/03/22 23:16:49 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <mlx_utils.h>

void	ft_mlx_put_pixel(t_imginfo *img, int x, int y, unsigned int color)
{
	int		offset;
	char	*dst;

	offset = y * img->size_line + x * (img->bits_per_pixel / CHAR_BIT);
	dst = img->addr + offset;
	*(unsigned int *)dst = color;
}
