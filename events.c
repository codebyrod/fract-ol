/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosousa- <rosousa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 11:41:52 by rosousa-          #+#    #+#             */
/*   Updated: 2026/02/02 16:11:31 by rosousa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include "minilibx-linux/mlx.h"
#include <X11/X.h>
#include <unistd.h>
#include <stdlib.h>

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->connection, fractal->img.img_ptr);
	mlx_destroy_window(fractal->connection, fractal->window);
	mlx_destroy_display(fractal->connection);
	free(fractal->connection);
	exit (EXIT_SUCCESS);
}

int	handle_arrows(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		close_handler(fractal);
	if (keysym == XK_Left)
		fractal->x_disp += 0.5 * fractal->zoom;
	if (keysym == XK_Right)
		fractal->x_disp -= 0.5 * fractal->zoom;
	if (keysym == XK_Up)
		fractal->y_disp -= 0.5 * fractal->zoom;
	if (keysym == XK_Down)
		fractal->y_disp += 0.5 * fractal->zoom;
	fractal_render(fractal);
	return (0);
}

int	handle_mouse(int button, int x, int y, t_fractal *fractal)
{
	(void)fractal;
	(void)x;
	(void)y;
	if (button == Button5)
		fractal->zoom *= 1.05;
	if (button == Button4)
		fractal->zoom *= 0.95;
	fractal_render(fractal);
	return (0);
}
