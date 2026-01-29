/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosousa- <rosousa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:11:45 by rosousa-          #+#    #+#             */
/*   Updated: 2026/01/29 20:03:31 by rosousa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	// int	offset;
	int	displacement; //DESLOCAMENTO
	int conv_bit_to_byte; //CONVERTE BIT EM BYTES
	char *addr_to_drawing; //ENDEREÇO PARA ESCREVER
	unsigned int *int_addr_drawing; //ENDEREÇO DO BLOCO PARA ESCREVER
	
	//CONVERTEMOS O BIT PARA BYTE
	conv_bit_to_byte = (img->bits_per_pixel / 8);
	
	//CALCULAMOS O PIXEL DE ONDE IREMOS PINTAR
	displacement = (img->line_len * y) + (x * conv_bit_to_byte);
	
	//FAZEMOS ARITMÉTICA DE PONTEIRO PARA IR ATÉ O PIXEL
	addr_to_drawing = displacement + img->img_pixels_ptr;
	
	//CONVERTEMOS O CHAR * PARA INT *
	int_addr_drawing = (unsigned int *)(addr_to_drawing);
	
	//DESREFERENCIAMOS PARA SETAR A NOVA COR;
	*int_addr_drawing = color;

	//TUDO ACIMA PODE SER RESUMIDO NESSAS DUAS LINHAS
	// offset = (img->line_len * y) + (x * (img->bits_per_pixel / 8));
	// *((unsigned int *)(offset + img->img_pixels_ptr)) = color;

}

void	handle_pixel(int x, int y, t_fractol *fractol)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	z.x = conv_scale(x, -2, 2, WIDTH);
	z.y = conv_scale(y, 2, -2, HEIGHT);
	
	while(i < fractol->iterations_definition)
	{
		z = calc_mandelbrot(z, c);
		fractol->hipotenusa = (z.x * z.x) * (z.y * z.y); 
		if(fractol->hipotenusa >= fractol->escape_value)
		{
			color = conv_scale(i, 0xff, 0x0000ff, fractol->iterations_definition);
			my_pixel_put(fractol->img.img_ptr, x, y, color);
		}
		my_pixel_put(fractol->img.img_ptr, x, y, 0x854200);
	}
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
			handle_pixel(x, y, &fractol);
			y++;
		}
		x++;
	}
}