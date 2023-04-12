/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 19:38:18 by sshimizu          #+#    #+#             */
/*   Updated: 2023/04/12 19:55:39 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CALC_H
# define CALC_H

# include <ft_complex.h>

int	calc_depth(t_complex z, t_complex c, int max_depth);
int	calc_depth_burning_ship(t_complex z, t_complex c, int max_depth);

#endif
