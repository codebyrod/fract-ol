/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosousa- <rosousa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 21:57:46 by rosousa-          #+#    #+#             */
/*   Updated: 2026/01/31 23:11:09 by rosousa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

double conv_scale(double pixel_coord, double new_max, double new_min, double old_max)
{
	t_conv_scale	n;
	n.old_min = 0;
	//distância absoluta percorrida
	n.distance_abs_start = pixel_coord - n.old_min;
	//Tamanho da antiga escala
	n.old_size = old_max - n.old_min;
	//Tamanho da nova escala
	n.new_size = new_max - new_min;
	//tamanho relativo da distância percorrida, vai retornar uma proporção
	n.rel_distance_traveled = n.distance_abs_start / n.old_size;
	//transformação da escala
	n.new_scale = n.new_size * n.rel_distance_traveled;
	//descola na nova escala o novo valor
	n.final_coord = n.new_scale + new_min;
	
	return (n.final_coord);
}

t_complex	calc_fractal(t_complex z1, t_complex z2)
{
	double	temp;
	t_complex result;

	temp = (z1.x * z1.x) - (z1.y * z1.y);
	result.y = (2 * z1.x * z1.y) + z2.y;
	result.x = temp + z2.x;

	return (result);
}

