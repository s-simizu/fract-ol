/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:54:04 by sshimizu          #+#    #+#             */
/*   Updated: 2023/04/12 13:55:07 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVE_H
# define MOVE_H

# include <display.h>

void	move_up(t_display *disp);
void	move_down(t_display *disp);
void	move_left(t_display *disp);
void	move_right(t_display *disp);

#endif
