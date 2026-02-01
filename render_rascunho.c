/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosousa- <rosousa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:11:45 by rosousa-          #+#    #+#             */
/*   Updated: 2026/02/01 19:56:35 by rosousa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static void	my_pixel_put(t_img *img, int x, int y, int color)
{
	// int	offset;
	// printf("Estou na my_pixel: 1\n");
	int	displacement; //DESLOCAMENTO
	int conv_bit_to_byte; //CONVERTE BIT EM BYTES
	char *addr_to_drawing; //ENDEREÇO PARA ESCREVER
	unsigned int *int_addr_drawing; //ENDEREÇO DO BLOCO PARA ESCREVER
	
	//CONVERTEMOS O BIT PARA BYTE
	conv_bit_to_byte = (img->bits_per_pixel / 8);
	// printf("Estou na my_pixel: 2\n");
	
	//CALCULAMOS O PIXEL DE ONDE IREMOS PINTAR
	displacement = (img->line_len * y) + (x * conv_bit_to_byte);
	// printf("Estou na my_pixel: 3\n");
	
	//FAZEMOS ARITMÉTICA DE PONTEIRO PARA IR ATÉ O PIXEL
	addr_to_drawing = displacement + img->img_pixels_ptr;
	// printf("Estou na my_pixel: 4\n");
	
	*(unsigned int *)addr_to_drawing = color;
	// printf("Estou na my_pixel: 5\n");
	
	// CONVERTEMOS O CHAR * PARA INT *
	int_addr_drawing = (unsigned int *)(addr_to_drawing);
	// printf("Estou na my_pixel: 5\n");
	
	//DESREFERENCIAMOS PARA SETAR A NOVA COR;
	*int_addr_drawing = (unsigned int)color;
	// printf("Estou na my_pixel: 6\n");

	// TUDO ACIMA PODE SER RESUMIDO NESSAS DUAS LINHAS
	// offset = (img->line_len * y) + (x * (img->bits_per_pixel / 8));
	// *(unsigned int *)(offset + img->img_pixels_ptr) = color;
}

void	set_data(int x, int y, t_complex *z, t_complex *c, t_fractal *fractal)
{
	z->x = 0.0;
	z->y = 0.0;
	c->x = (conv_scale(x, -2, 2, WIDTH) * fractal->zoom) + fractal->x_offset;
	c->y = (conv_scale(y, 2, -2, HEIGHT) * fractal->zoom) + fractal->y_offset;
	if(!ft_strscmp("julia", fractal->name_window))
	{
		z->x = c->x;
		z->y = c->y;
		c->x = fractal->julia_c_x;
		c->y = fractal->julia_c_y;
	}
}

static void	handle_pixel(int x, int y, t_complex z, t_complex c, t_fractal *fractal)
{
	int			i;
	int			color;

	i = 0;
	set_data(x, y, &z, &c, fractal);
	while(i < fractal->iterations_definition)
	{
		z = calc_fractal(z, c);
		fractal->hipotenusa = (z.x * z.x) + (z.y * z.y);
		if(fractal->hipotenusa > fractal->escape_value)
		{
			color = conv_scale(i, 0x000000, MAGENTA_BURST, fractal->iterations_definition);
			my_pixel_put(&fractal->img, x, y, color);
			return;
		}
		i++;
	}
	my_pixel_put(&fractal->img, x, y, LIME_SHOCK);
}

void	fractal_render(t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int	x;
	int	y;

	(void)z.x;
	(void)c.x;
	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			handle_pixel(x, y, z, c, fractal);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(fractal->connection,
							fractal->window,
							fractal->img.img_ptr,
							0, 0);
}
