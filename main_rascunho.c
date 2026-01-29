/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_rascunho.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosousa- <rosousa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 05:56:42 by rosousa-          #+#    #+#             */
/*   Updated: 2026/01/29 19:29:33 by rosousa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex   sum_complex(t_complex z1, t_complex z2)
{
    t_complex   result;

    result.x = z1.x + z2.x;
    result.y = z1.y + z2.y;
    return result;
}

void	color_screen(t_var *data, int color)
{
	int y;
	int x;
	
	y = 0;
	while(y < SIDE_LEN)
	{
		x = 0;
		while(x < SIDE_LEN)
		{
			// mlx_pixel_put(data->mlx, data->win, x, y, color);
			my_pixel_put(&data->img, x, y, color);
			x++;
		}
		y++;
	}
}

// int encode_rgb(byte red, byte green, byte blue)
// {
// 	return (red << 16 | green << 8 | blue);
// }

// int	handle_input(int tecla, t_mlx_data *data)
// {
// 	(void)data;
// 	if(tecla == XK_Escape)
// 	{
// 		printf("Apertou a tecla esc\n\n");
// 		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
// 		mlx_destroy_display(data->mlx_ptr);
// 		free(data->mlx_ptr);
// 		exit(1);
// 	}
// 	else
// 		printf("Apertou a tecla %d\n\n", tecla);
// 	return (0);
// }

int f(int keysym, t_var *data)
{
	if (keysym == XK_r)
		color_screen(data, 0xff0000);
	else if (keysym == XK_g)
		color_screen(data, 0xff00);
	else if (keysym == XK_b)
		color_screen(data, 0xff);
	else if(keysym == XK_Escape)
		exit(1);
		
	//COLOCANDO ESSAS LINHAS ABAIXO PARA JOGAR O QUE ESTÁ RENDERIZADO PARA UM BUFFER DE IMG
	mlx_put_image_to_window(data->mlx,
							data->win,
							data->img.img_ptr,
							0, 0);
	return (0);
}

int	main(void)
{
	t_var       vars;
	// t_mlx_data data;
	// int i;
	// int j;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, SIDE_LEN, SIDE_LEN, "My 1* window");
	// printf("CNN: %p", mlx_connection);
	
	// i = WIDTH * 0.1;
	// while (i < WIDTH * 0.8)
	// {
	// 	j = HEIGHT * 0.1;
	// 	while (j < HEIGHT * 0.8)
	// 	{
	// 		mlx_pixel_put(mlx_connection, mlx_window, j, i, rand() % 0x1000000);
	// 		j++;
	// 	}
	// 	i++;
	// }
	// mlx_string_put(mlx_connection, mlx_window, WIDTH * 0.7, HEIGHT * 0.9, rand() % 0x1000000,"Rodrigo_Conseguiu");
	// mlx_hook(data.mlx_win, 2, 1L<<0, handle_input, &data);
	
	//CREATE IMG
	vars.img.img_ptr = mlx_new_image(vars.mlx, SIDE_LEN, SIDE_LEN);
	
	//INPUT IMAGE?
	vars.img.img_pixels_ptr = mlx_get_data_addr(vars.img.img_ptr, 
												 &vars.img.bits_per_pixel, 
												 &vars.img.line_len, 
												 &vars.img.endian);
	mlx_key_hook(vars.win, f, &vars);
	
	mlx_loop(vars.mlx);
}
