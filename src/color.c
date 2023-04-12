/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:36:38 by sshimizu          #+#    #+#             */
/*   Updated: 2023/04/12 21:29:30 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <color.h>
#include <math.h>

#define BRACK 0x00000000
#define WHITE 0x00FFFFFF
#define RED 0x00FF0000
#define GREEN 0x0000FF00
#define BRUE 0x000000FF

t_color	get_red(double brightness)
{
	if (brightness > 1.0)
		brightness = 1.0;
	return ((unsigned char)(0xFF * brightness) << 16);
}

t_color	get_color(int depth, int max_depth)
{
	double	brightness;

	brightness = log(depth) / log(max_depth);
	if (brightness == 1.0 || brightness < 0.2)
		return (BRACK);
	return (get_red(brightness));
}
