/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosousa- <rosousa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 07:40:56 by rosousa-          #+#    #+#             */
/*   Updated: 2026/01/30 06:07:45 by rosousa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

#define WIDTH 800
#define HEIGHT 800
#define MALLOC_ERROR 1

#include "minilibx-linux/mlx.h"
#include "X11/keysym.h"

#include <stdio.h> //APAGAR
#include <stdlib.h>

typedef unsigned char byte;

//Fazer minhas próprias cores
#define BLACK       0x000000  // RGB(0, 0, 0)
#define WHITE       0xFFFFFF  // RGB(255, 255, 255)
#define RED         0xFF0000  // RGB(255, 0, 0)
#define GREEN       0x00FF00  // RGB(0, 255, 0)
#define BLUE        0x0000FF  // RGB(0, 0, 255)

// Psychedelic colors
#define MAGENTA_BURST   0xFF00FF  // A vibrant magenta
#define LIME_SHOCK      0xCCFF00  // A blinding lime
#define NEON_ORANGE     0xFF6600  // A blazing neon orange
#define PSYCHEDELIC_PURPLE 0x660066  // A deep purple
#define AQUA_DREAM      0x33CCCC  // A bright turquoise
#define HOT_PINK        0xFF66B2  // As the name suggests!
#define ELECTRIC_BLUE   0x0066FF  // A radiant blue
#define LAVA_RED        0xFF3300  // A bright, molten red

typedef struct s_complex
{
	double	x;
	double	y;
	double	real;
	double	imag;
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
	double	hipotenusa;
	
}	t_fractol;

//STRUCT PARA CONV_SCALE
typedef struct s_conv_scale
{
	double	old_min;
	double	old_size;
	double	new_size;
	double	distance_abs_start;
	double  rel_distance_traveled;
	double	new_scale;
	double	final_coord;
}	t_conv_scale;


//FUNÇÕES DE ESTUDO

//init
void	fractol_init(t_fractol *fractol);
void	data_init(t_fractol *fractol);

//render
void	fractol_render(t_fractol *fractol);
void	handle_pixel(int x, int y, t_fractol *fractol);

//math
double	conv_scale(double pixel_coord, double new_max, double new_min, double old_max);
t_complex	calc_mandelbrot(t_complex z1, t_complex z2);


#endif