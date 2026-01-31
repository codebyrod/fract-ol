/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosousa- <rosousa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 11:26:10 by rosousa-          #+#    #+#             */
/*   Updated: 2026/01/30 06:44:18 by rosousa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	main()
{
	t_fractal fractal; //Mudar para fractral
	printf("Estou na main \n");
	fractal_init(&fractal);
	printf("Estou na main: passei do frac_init \n");
	fractal_render(&fractal);
	printf("Estou na main: passei do frac_rend \n");
	// mlx_destroy_display(fractal.connection);
	// mlx_destroy_window(fractal.connection, fractal.window);
	mlx_loop(fractal.connection);
}