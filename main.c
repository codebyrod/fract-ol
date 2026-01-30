/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosousa- <rosousa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 11:26:10 by rosousa-          #+#    #+#             */
/*   Updated: 2026/01/30 04:44:28 by rosousa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main()
{
	t_fractol fractol; //Mudar para fractral
	printf("Estou na main \n");
	fractol_init(&fractol);
	printf("Estou na main: passei do frac_init \n");
	fractol_render(&fractol);
	printf("Estou na main: passei do frac_rend \n");
	mlx_loop(fractol.connection);
}