/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosousa- <rosousa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 11:41:52 by rosousa-          #+#    #+#             */
/*   Updated: 2026/01/31 18:16:55 by rosousa-         ###   ########.fr       */
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
		fractal->x_offset += 0.5 * fractal->zoom;
	if (keysym == XK_Right)
		fractal->x_offset -= 0.5 * fractal->zoom;
	if (keysym == XK_Up)
		fractal->y_offset -= 0.5 * fractal->zoom;
	if (keysym == XK_Down)
		fractal->y_offset += 0.5 * fractal->zoom;
	fractal_render(fractal);
	return 0;
}


// int (*f)(int button, int x, int y, void *param)
int	handle_mouse(int button, int x, int y, t_fractal *fractal)
{
	(void)fractal;
	(void)x;
	(void)y;
	// printf("button: %d\n", button);
	// printf("X: %d; Y: %d\n", x, y);
	if(button == Button5) //VERIFICAR SE O MOVIMENTO DO MOUSE ESTÁ CORRETO
		fractal->zoom *= 1.05;
	if(button == Button4) // VERIFICAR SE O MOVIMENTO DO MOUSE ESTÁ CORRETO
		fractal->zoom *= 0.95;
	fractal_render(fractal);
	return (0);
}