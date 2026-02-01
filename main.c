/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosousa- <rosousa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 11:26:10 by rosousa-          #+#    #+#             */
/*   Updated: 2026/02/01 20:07:57 by rosousa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	verify_args(int ac, char **av)
{
	if (ac == 1)
		message_error();
	if ((!ft_strscmp(av[1], "mandelbrot") && ac == 2) ||
		(!ft_strscmp(av[1], "julia") && ac == 4 ))
		return ;
	else
		message_error();
}

int	main(int ac, char **av)
{
	t_fractal fractal; //Mudar para fractral
	// printf("Estou na main \n");
	// fractal.name_window = "Janela";
	verify_args(ac, av);
	fractal_init(&fractal, ac, av);
	printf("Estou na main: passei do frac_init \n");
	fractal_render(&fractal);
	printf("Estou na main: passei do frac_rend \n");
	// mlx_destroy_display(fractal.connection);
	// mlx_destroy_window(fractal.connection, fractal.window);
	mlx_loop(fractal.connection);
}