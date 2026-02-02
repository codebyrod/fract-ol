/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosousa- <rosousa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:11:45 by rosousa-          #+#    #+#             */
/*   Updated: 2026/02/02 14:23:20 by rosousa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static void	my_pixel_put(t_img *img, int x, int y, int color)
{
	int				displacement;
	int				conv_bit_to_byte;
	char			*addr_to_drawing;
	unsigned int	*int_addr_drawing;

	conv_bit_to_byte = (img->bits_per_pixel / 8);
	displacement = (img->line_len * y) + (x * conv_bit_to_byte);
	addr_to_drawing = displacement + img->img_pixels_ptr;
	*(unsigned int *)addr_to_drawing = color;
	int_addr_drawing = (unsigned int *)(addr_to_drawing);
	*int_addr_drawing = (unsigned int)color;
}

void	set_data(t_coord cd, t_cpx *z, t_cpx *c, t_fractal *fractal)
{
	z->x = 0.0;
	z->y = 0.0;
	c->x = (conv_scale(cd.x, 2, -2, WIDTH) * fractal->zoom) + fractal->x_disp;
	c->y = (conv_scale(cd.y, -2, 2, HEIGHT) * fractal->zoom) + fractal->y_disp;
	if (!ft_strscmp("Julia", fractal->name_window))
	{
		z->x = c->x;
		z->y = c->y;
		c->x = fractal->julia_c_x;
		c->y = fractal->julia_c_y;
	}
}

static void	handle_pixel(t_coord cd, t_cpx z, t_cpx c, t_fractal *fractal)
{
	int	i;
	int	color;

	i = 0;
	set_data(cd, &z, &c, fractal);
	while (i < fractal->it_def)
	{
		z = calc_fractal(z, c);
		fractal->hipotenusa = (z.x * z.x) + (z.y * z.y);
		if (fractal->hipotenusa > fractal->escape_value)
		{
			color = conv_scale(i, 0xFFFFFF, MAGENTA_BURST, fractal->it_def);
			my_pixel_put(&fractal->img, cd.x, cd.y, color);
			return ;
		}
		i++;
	}
	my_pixel_put(&fractal->img, cd.x, cd.y, LIME_SHOCK);
}

void	fractal_render(t_fractal *fractal)
{
	t_cpx		z;
	t_cpx		c;
	t_coord		coord;

	(void)z.x;
	(void)c.x;
	coord.x = 0;
	while (coord.x < WIDTH)
	{
		coord.y = 0;
		while (coord.y < HEIGHT)
		{
			handle_pixel(coord, z, c, fractal);
			coord.y++;
		}
		coord.x++;
	}
	mlx_put_image_to_window(fractal->connection,
		fractal->window,
		fractal->img.img_ptr,
		0, 0);
}
