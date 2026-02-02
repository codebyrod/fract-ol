/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosousa- <rosousa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 23:28:08 by rosousa-          #+#    #+#             */
/*   Updated: 2026/02/02 12:14:41 by rosousa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

double	ft_atodou(char *str)
{
	int		i;
	int		signal;
	double	number;

	i = 0;
	signal = 1;
	check_args_julia(str);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signal = -1;
		i++;
	}
	if (str[i] < '0' || str[i] > '9')
		message_error();
	number = calc_double(&str[i]);
	return (number * signal);
}

double	calc_double(char *str)
{
	double	integer_part;
	double	frac_part;
	double	div;
	int		i;

	i = 0;
	div = 1.0;
	integer_part = 0.0;
	frac_part = 0.0;
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '.' && str)
	{
		integer_part = (integer_part * 10) + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
			i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		div = div / 10;
		frac_part = frac_part + (str[i] - 48) * div;
		i++;
	}
	return (integer_part + frac_part);
}

void	check_args_julia(char *str)
{
	int	i;
	int	dot_count;

	i = 0;
	dot_count = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		message_error();
	while (str[i])
	{
		if (str[i] == '.')
		{
			dot_count++;
			if (dot_count > 1)
				message_error();
		}
		else if (str[i] < '0' || str[i] > '9')
			message_error();
		i++;
	}
}
