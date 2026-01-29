/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosousa- <rosousa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 21:57:46 by rosousa-          #+#    #+#             */
/*   Updated: 2026/01/29 20:02:07 by rosousa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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



t_complex	calc_mandelbrot(t_complex z1, t_complex z2)
{
	t_complex z;
	t_complex c;
	double	temp;
	
	temp = (z1.real * z1.real) - (z1.imag * z1.imag);
	z1.imag = 2 * z1.real * z1.imag;
	z1.real = temp;

	z.real = z1.real + z2.real;
	z.imag = z1.imag + z2.imag;
	
	
	
	
	// temp_real = (z.real * z.real) - (z.i * z.i);
	// z.i = 2 * z.real * z.i;
	// z.real = temp_real;
	
	// //adicionando a segunda parte da fórmula, o c
	// z.real = z.real + c.real;
	// z.i = z.i + c.i;

	
	
	
}
