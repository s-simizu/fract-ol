/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 22:27:30 by sshimizu          #+#    #+#             */
/*   Updated: 2023/03/26 19:27:53 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_UTILS_H
# define MLX_UTILS_H

typedef struct s_imginfo
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
}				t_imginfo;

typedef struct s_display
{
	void		*mlx;
	void		*win;
	t_imginfo	imginfo;
	int			width;
	int			height;
}				t_display;

t_display		new_display(int width, int height);
void			free_display(t_display *display);
void			mlx_put_pixel_to_image(t_imginfo *imginfo, int x, int y,
					unsigned int color);

#endif
