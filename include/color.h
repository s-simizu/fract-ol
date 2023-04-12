/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:35:11 by sshimizu          #+#    #+#             */
/*   Updated: 2023/04/13 00:01:38 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include <display.h>

# define BLACK 0x00000000

typedef struct s_display	t_display;

unsigned int				get_color(t_display *disp, int depth,
								int max_depth);
void						change_red(t_display *disp);
void						change_green(t_display *disp);
void						change_blue(t_display *disp);

#endif
