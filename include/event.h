/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:39:20 by sshimizu          #+#    #+#             */
/*   Updated: 2023/04/12 15:43:20 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_H
# define EVENT_H

# include <display.h>

int	mouse_event(int button, int x, int y, t_display *disp);
int	key_event(int keycode, t_display *disp);
int	close_event(t_display *disp);

#endif
