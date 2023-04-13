/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 20:52:16 by sshimizu          #+#    #+#             */
/*   Updated: 2023/04/13 10:30:51 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

# include <color.h>
# include <fractal.h>
# include <ft_complex.h>

typedef struct s_imginfo
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
}					t_imginfo;

typedef struct s_display
{
	void			*mlx;
	void			*win;
	t_imginfo		imginfo;
	int				width;
	int				height;
	int				max_depth;
	double			zoom_level;
	t_complex		center;
	t_fractal		fractal;
	t_complex		julia_param;
	unsigned int	color;
}					t_display;

void				init_display(t_display *disp, char *disp_size);
void				destroy_display(t_display *disp);

#endif
