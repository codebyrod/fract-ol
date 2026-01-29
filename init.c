/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosousa- <rosousa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 11:55:40 by rosousa-          #+#    #+#             */
/*   Updated: 2026/01/29 16:13:20 by rosousa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	data_init(t_fractol *fractol)
{
	fractol->escape_value = 4;
	
}

void	fractol_init(t_fractol *fractol)
{
	fractol->connection = mlx_init();
	// verificar se deu certo, se deu errado free;
	fractol->window = mlx_new_window(fractol->connection,
										WIDTH,
										HEIGHT,
										fractol->name_window);
	// verificar se deu certo, se deu errado free;
	fractol->img.img_ptr = mlx_new_image(fractol->connection,
										WIDTH,
										HEIGHT);
	// verificar se deu certo, se deu errado free;
	fractol->img.img_pixels_ptr = mlx_get_data_addr(fractol->img.img_ptr,
													&fractol->img.bits_per_pixel,
													&fractol->img.line_len,
													&fractol->img.endian);
	// events_init() // TODO
	data_init(&fractol);
}
