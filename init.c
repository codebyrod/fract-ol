/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosousa- <rosousa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 11:55:40 by rosousa-          #+#    #+#             */
/*   Updated: 2026/02/01 20:07:59 by rosousa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	data_init(t_fractal *fractal, int ac, char **av)
{
	fractal->name_window = av[1];
	fractal->escape_value = 4;
	fractal->iterations_definition = 80;
	fractal->x_offset = 0;
	fractal->y_offset = 0;
	fractal->zoom = 1;
	if(ac == 4)
	{
		fractal->julia_c_x = ft_atodou(av[2]);
		fractal->julia_c_y = ft_atodou(av[3]);
	}
}

static void	events_init(t_fractal *fractal)
{
	// printf("Estou em events\n");
	// mlx_hook(fractal->window, KeyPress, KeyPressMask, handler_arrows, fractal);
	mlx_hook(fractal->window, KeyPress, KeyPressMask, handle_arrows, fractal);
	mlx_hook(fractal->window, ButtonPress, ButtonPressMask, handle_mouse, fractal);
	
}

void	fractal_init(t_fractal *fractal, int ac, char **av)
{
	data_init(fractal, ac, av);
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
	
	events_init(fractal);
	
}
