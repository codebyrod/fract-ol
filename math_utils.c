/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosousa- <rosousa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 21:57:46 by rosousa-          #+#    #+#             */
/*   Updated: 2026/02/02 16:17:04 by rosousa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

double	conv_scale(double px_coord, double n_max, double n_min, double old_max)
{
	t_conv_scale	n;

	n.old_min = 0;
	n.distance_abs_start = px_coord - n.old_min;
	n.old_size = old_max - n.old_min;
	n.new_size = n_max - n_min;
	n.rel_distance_traveled = n.distance_abs_start / n.old_size;
	n.new_scale = n.new_size * n.rel_distance_traveled;
	n.final_coord = n.new_scale + n_min;
	return (n.final_coord);
}

t_cpx	calc_fractal(t_cpx z1, t_cpx z2)
{
	double		temp;
	t_cpx		result;

	temp = (z1.x * z1.x) - (z1.y * z1.y);
	result.y = (2 * z1.x * z1.y) + z2.y;
	result.x = temp + z2.x;
	return (result);
}
