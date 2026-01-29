/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosousa- <rosousa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 00:38:07 by rosousa-          #+#    #+#             */
/*   Updated: 2026/01/29 16:12:49 by rosousa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calc_form(void)
{
	typedef struct s_complex
	{
		double real;
		double i;

	} t_complex;
	
	t_complex z;
	t_complex c;
	double temp_real;

	int iter;

	
	z.real = 0;
	z.i = 0;
	
	c.real = 0.25;
	c.i = 0.4;
	
	iter = 0;
	while(iter < 42)
	{
		//Formula geral = z^2 + C
		temp_real = (z.real * z.real) - (z.i * z.i);
		z.i = 2 * z.real * z.i;
		z.real = temp_real;
		
		//adicionando a segunda parte da fórmula, o c
		z.real = z.real + c.real;
		z.i = z.i + c.i;
		
		iter++;
		
		printf("iteration n -> %d. Real: %f, Imag: %f\n", iter, z.real, z.i);
	}
}
