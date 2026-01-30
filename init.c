/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosousa- <rosousa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 11:55:40 by rosousa-          #+#    #+#             */
/*   Updated: 2026/01/30 06:19:33 by rosousa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	data_init(t_fractal *fractal)
{
	fractal->escape_value = 4;
	fractal->iterations_definition = 80;
}

void	fractal_init(t_fractal *fractal)
{
	fractal->connection = mlx_init();
	// verificar se deu certo, se deu errado free;
	fractal->window = mlx_new_window(fractal->connection,
										WIDTH,
										HEIGHT,
										fractal->name_window);
	// verificar se deu certo, se deu errado free;
	fractal->img.img_ptr = mlx_new_image(fractal->connection,
										WIDTH,
										HEIGHT);
	// verificar se deu certo, se deu errado free;
	fractal->img.img_pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr,
													&fractal->img.bits_per_pixel,
													&fractal->img.line_len,
													&fractal->img.endian);
	// events_init() // TODO
	data_init(fractal);
}
