/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosousa- <rosousa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 07:40:56 by rosousa-          #+#    #+#             */
/*   Updated: 2026/02/02 14:20:37 by rosousa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include "minilibx-linux/mlx.h"
# include "X11/keysym.h"
# include "X11/X.h"
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

# define WIDTH	800
# define HEIGHT	800

// # define STDOUT_FILENO	1
// # define STDERR_FILENO	2

# define BLACK				0x000000
# define WHITE				0xFFFFFF
# define RED				0xFF0000
# define GREEN				0x00FF00
# define BLUE				0x0000FF
# define MAGENTA_BURST		0xFF00FF
# define LIME_SHOCK			0xCCFF00
# define NEON_ORANGE		0xFF6600
# define PSYCHEDELIC_PURPLE	0x660066
# define AQUA_DREAM			0x33CCCC
# define HOT_PINK			0xFF66B2
# define ELECTRIC_BLUE		0x0066FF
# define LAVA_RED			0xFF3300

typedef struct s_cpx
{
	double	x;
	double	y;
}	t_cpx;

typedef struct s_img
{
	void	*img_ptr;
	char	*img_pixels_ptr;
	int		bits_per_pixel;
	int		endian;
	int		line_len;
}	t_img;

typedef struct s_fractal
{
	void	*connection;
	void	*window;
	char	*name_window;
	t_img	img;
	double	escape_value;
	double	it_def;
	double	hipotenusa;
	double	x_disp;
	double	y_disp;
	double	zoom;
	double	julia_c_x;
	double	julia_c_y;
}	t_fractal;

typedef struct s_conv_scale
{
	double	old_min;
	double	old_size;
	double	new_size;
	double	distance_abs_start;
	double	rel_distance_traveled;
	double	new_scale;
	double	final_coord;
}	t_conv_scale;

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

void	fractal_init(t_fractal *fractal, int ac, char **av);
void	data_init(t_fractal *fractal, int ac, char **av);
void	fractal_render(t_fractal *fractal);
void	set_data(t_coord coord, t_cpx *z, t_cpx *c, t_fractal *fractal);
double	conv_scale(double px_coord, double n_max, double n_min, double old_max);
t_cpx	calc_fractal(t_cpx z1, t_cpx z2);
int		handle_arrows(int keysym, t_fractal *fractol);
int		handle_mouse(int button, int x, int y, t_fractal *fractal);
int		close_handler(t_fractal *fractal);
int		ft_strscmp(char *str1, char *str2);
void	ft_putstr_fd(char *str, int fd);
void	check_args(int ac, char **av);
double	ft_atodou(char *str);
double	calc_double(char *str);
void	check_args_julia(char *str);
void	message_error(void);
void	close_error(t_fractal *fractal, char *str);

#endif