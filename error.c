/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosousa- <rosousa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 20:37:01 by rosousa-          #+#    #+#             */
/*   Updated: 2026/01/31 22:14:00 by rosousa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	message_error(void)
{
	ft_putstr_fd("ERROR!\n", 2);
	ft_putstr_fd("Please use one of the options below:\n", 2);
	ft_putstr_fd("  ./fractol mandelbrot\n", 2);
	ft_putstr_fd("  ./fractol julia <c_re> <c_im> \n", 2);
	exit (1);
}
