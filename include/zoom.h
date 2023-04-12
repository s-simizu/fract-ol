/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:55:15 by sshimizu          #+#    #+#             */
/*   Updated: 2023/04/12 13:56:01 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOOM_H
# define ZOOM_H

# include <display.h>

void	zoom_in(t_display *disp, int x, int y);
void	zoom_out(t_display *disp, int x, int y);

#endif
