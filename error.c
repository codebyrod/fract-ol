/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosousa- <rosousa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 20:37:01 by rosousa-          #+#    #+#             */
/*   Updated: 2026/02/02 14:25:14 by rosousa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	message_error(void)
{
	ft_putstr_fd("┌────────────────────────────────────────┐\n", STDERR_FILENO);
	ft_putstr_fd("| Fract-ol École 42                      |\n", STDERR_FILENO);
	ft_putstr_fd("|                                        |\n", STDERR_FILENO);
	ft_putstr_fd("| HELP --------------------------------- |\n", STDERR_FILENO);
	ft_putstr_fd("| To execute fractals, use the commands  |\n", STDERR_FILENO);
	ft_putstr_fd("| -------------------------------------- |\n", STDERR_FILENO);
	ft_putstr_fd("| ./fractol Mandelbrot                   |\n", STDERR_FILENO);
	ft_putstr_fd("| ./fractol Julia <real> <imag>          |\n", STDERR_FILENO);
	ft_putstr_fd("|                                        |\n", STDERR_FILENO);
	ft_putstr_fd("| EXAMPLE------------------------(Julia) |\n", STDERR_FILENO);
	ft_putstr_fd("| ./fractol Julia 0 0.8                  |\n", STDERR_FILENO);
	ft_putstr_fd("| ./fractol Julia -0.835 -0.2321         |\n", STDERR_FILENO);
	ft_putstr_fd("| ./fractol Julia 0.285  0.01            |\n", STDERR_FILENO);
	ft_putstr_fd("└────────────────────────────────────────┘\n", STDERR_FILENO);

	exit (EXIT_FAILURE);
}

void	close_error(t_fractal *fractal, char *str)
{
	if (!ft_strscmp(str, "connection"))
		ft_putstr_fd("Problem with the display connection.", 2);
	if (!ft_strscmp(str, "window"))
	{
		mlx_destroy_display(fractal->connection);
		free(fractal->connection);
		ft_putstr_fd("Problem with the window connection.", 2);
	}
	if (!ft_strscmp(str, "img_ptr"))
	{
		mlx_destroy_window(fractal->connection, fractal->window);
		mlx_destroy_display(fractal->connection);
		free(fractal->connection);
		ft_putstr_fd("Problem with the image connection.", 2);
	}
	if (!ft_strscmp(str, "img_pixels_ptr"))
	{
		mlx_destroy_image(fractal->connection, fractal->img.img_ptr);
		mlx_destroy_window(fractal->connection, fractal->window);
		mlx_destroy_display(fractal->connection);
		free(fractal->connection);
		ft_putstr_fd("Problem with the image_ptr connection.", 2);
	}
	exit (EXIT_FAILURE);
}
