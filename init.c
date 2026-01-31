/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosousa- <rosousa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 11:55:40 by rosousa-          #+#    #+#             */
/*   Updated: 2026/01/31 18:08:32 by rosousa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	data_init(t_fractal *fractal)
{
	fractal->escape_value = 4;
	fractal->iterations_definition = 42;
	fractal->x_offset = 0;
	fractal->y_offset = 0;
	fractal->zoom = 1;
}

static void	events_init(t_fractal *fractal)
{
	// printf("Estou em events\n");
	// mlx_hook(fractal->window, KeyPress, KeyPressMask, handler_arrows, fractal);
	mlx_hook(fractal->window, KeyPress, KeyPressMask, handle_arrows, fractal);
	mlx_hook(fractal->window, ButtonPress, ButtonPressMask, handle_mouse, fractal);
	
}

void	fractal_init(t_fractal *fractal)
{
	printf("Estou na f_inti\n");
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
	
	printf("Estou na f_inti2\n");
	events_init(fractal);
	data_init(fractal);
}
