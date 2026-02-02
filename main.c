/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosousa- <rosousa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 11:26:10 by rosousa-          #+#    #+#             */
/*   Updated: 2026/02/02 16:16:45 by rosousa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	main(int ac, char **av)
{
	t_fractal	fractal;

	check_args(ac, av);
	fractal_init(&fractal, ac, av);
	fractal_render(&fractal);
	mlx_loop(fractal.connection);
}
