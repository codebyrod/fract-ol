/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosousa- <rosousa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 07:40:56 by rosousa-          #+#    #+#             */
/*   Updated: 2026/01/29 12:16:42 by rosousa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

#define WIDTH 1500
#define HEIGHT 1500
#define SIDE_LEN 1400
#define MALLOC_ERROR 1

#include "minilibx-linux/mlx.h"
#include "X11/keysym.h"

#include <stdio.h> //APAGAR
#include <stdlib.h>

typedef unsigned char byte;

struct s_complex
{
	double	x;
	double	y;
}	t_complex;


typedef struct s_img
{
	void	*img_ptr;
	char	*img_pixels_ptr;
	int	    bits_per_pixel;
	int     endian;
	int	    line_len;
}    t_img;


//STRUCT USADA PARA PUT_IMG
typedef struct s_fractol
{
	void	*connection;
	void	*window;
	char	*name_window;
	t_img	img;

	//hooks member variaveis
	double	escape_value;
	double	iterations_definition;
	
}	t_fractol;



//FUNÇÕES DE ESTUDO
// int encode_rgb(byte red, byte green, byte blue);
// int	handle_input(int tecla, t_mlx_data *data);
// int f(int keysym, t_var *data);

void	fractol_init(t_fractol *fractol);
void	data_init(t_fractol *fractol);



#endif