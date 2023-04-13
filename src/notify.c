/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   notify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 13:26:20 by sshimizu          #+#    #+#             */
/*   Updated: 2023/04/13 14:01:18 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <display.h>
#include <draw.h>

int	destroy_notify(t_display *disp)
{
	destroy_display(disp);
	return (0);
}

int	map_notify(t_display *disp)
{
	draw(disp);
	return (0);
}
