/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 21:35:57 by sshimizu          #+#    #+#             */
/*   Updated: 2023/04/11 03:48:11 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANDELBROT_H
# define MANDELBROT_H

# include <ft_complex.h>
# include <mlx_utils.h>

t_complex	point_to_complex(t_display *disp, int x, int y);
int			mandelbrot_depth(t_display *disp, int x, int y, int max_depth);

#endif
