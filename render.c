/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosousa- <rosousa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:11:45 by rosousa-          #+#    #+#             */
/*   Updated: 2026/01/30 05:49:28 by rosousa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	my_pixel_put(t_img *img, int x, int y, int color)
{
	int	offset;
	// printf("Estou na my_pixel: 1\n");
	// int	displacement; //DESLOCAMENTO
	// int conv_bit_to_byte; //CONVERTE BIT EM BYTES
	// char *addr_to_drawing; //ENDEREÇO PARA ESCREVER
	// // unsigned int *int_addr_drawing; //ENDEREÇO DO BLOCO PARA ESCREVER
	
	// //CONVERTEMOS O BIT PARA BYTE
	// conv_bit_to_byte = (img->bits_per_pixel / 8);
	// printf("Estou na my_pixel: 2\n");
	
	// //CALCULAMOS O PIXEL DE ONDE IREMOS PINTAR
	// displacement = (img->line_len * y) + (x * conv_bit_to_byte);
	// printf("Estou na my_pixel: 3\n");
	
	// //FAZEMOS ARITMÉTICA DE PONTEIRO PARA IR ATÉ O PIXEL
	// addr_to_drawing = displacement + img->img_pixels_ptr;
	// printf("Estou na my_pixel: 4\n");
	
	// *(unsigned int *)addr_to_drawing = color;
	// printf("Estou na my_pixel: 5\n");
	
	//CONVERTEMOS O CHAR * PARA INT *
	// int_addr_drawing = (unsigned int *)(addr_to_drawing);
	// printf("Estou na my_pixel: 5\n");
	
	// //DESREFERENCIAMOS PARA SETAR A NOVA COR;
	// *int_addr_drawing = (unsigned int)color;
	// printf("Estou na my_pixel: 6\n");

	// TUDO ACIMA PODE SER RESUMIDO NESSAS DUAS LINHAS
	offset = (img->line_len * y) + (x * (img->bits_per_pixel / 8));
	*(unsigned int *)(offset + img->img_pixels_ptr) = color;
}

void	handle_pixel(int x, int y, t_fractol *fractol)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.x = 0.0;
	z.y = 0.0;
	
	//pixel coordenadas
	c.x = conv_scale(x, -2, 2, WIDTH);
	c.y = conv_scale(y, 2, -2, HEIGHT);
	
	// printf("Estou na handle: 1\n");
	while(i < fractol->iterations_definition)
	{
		z = calc_mandelbrot(z, c);
		// z = sum_cpx(square_cpx(z), c);
		// z = square_and_sum(z, c);
		// printf("[%d]: Valor de Z.X: %f\n", i, z.x);
		// printf("[%d]: Valor de Z.Y: %f\n", i, z.y);
		fractol->hipotenusa = (z.x * z.x) * (z.y * z.y);
		// printf("Estou na handle: 2\n");
		// printf("Hipostenusa: %f\n", fractol->hipotenusa);
		if(fractol->hipotenusa > fractol->escape_value)
		{
			color = conv_scale(i, BLACK, WHITE, fractol->iterations_definition);
			// printf("Estou na handle: 3\n");
			my_pixel_put(&fractol->img, x, y, color);
			return;
		}
		i++;
	}
	// color = conv_scale(i, BLUE, RED, fractol->iterations_definition);
	my_pixel_put(&fractol->img, x, y, PSYCHEDELIC_PURPLE);
}

void	fractol_render(t_fractol *fractol)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			handle_pixel(x, y, fractol);
			// my_pixel_put(fractol->img.img_ptr, x, y, 0xff0000);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(fractol->connection,
							fractol->window,
							fractol->img.img_ptr,
							0, 0);
}