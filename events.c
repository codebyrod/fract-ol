/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosousa- <rosousa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 11:41:52 by rosousa-          #+#    #+#             */
/*   Updated: 2026/01/31 14:14:20 by rosousa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include "minilibx-linux/mlx.h"
#include <X11/X.h>
#include <stdio.h>
#include <stdlib.h>

void	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->connection, fractal->img.img_ptr);
	mlx_destroy_window(fractal->connection, fractal->window);
	mlx_destroy_display(fractal->connection);
	free(fractal->connection);
	exit(0);
}

int	handle_arrows(int keysym, t_fractal *fractal)
{
	// printf("to dentro da key_handler\n");
	
	if (keysym == XK_Escape)
		close_handler(fractal);
	if (keysym == XK_Left)
		fractal->x_offset += 0.5;
	if (keysym == XK_Right)
		fractal->x_offset -= 0.5;
	if (keysym == XK_Up)
		fractal->y_offset -= 0.5;
	if (keysym == XK_Down)
		fractal->y_offset += 0.5;
	fractal_render(fractal);
	return 0;
}