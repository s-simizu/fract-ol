/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   depth.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 19:38:18 by sshimizu          #+#    #+#             */
/*   Updated: 2023/04/12 23:12:04 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEPTH_H
# define DEPTH_H

# include <ft_complex.h>

int	depth(t_complex z, t_complex c, int max_depth);
int	depth_burning_ship(t_complex z, t_complex c, int max_depth);

#endif
