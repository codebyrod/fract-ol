/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosousa- <rosousa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 18:30:57 by rosousa-          #+#    #+#             */
/*   Updated: 2026/01/31 23:11:12 by rosousa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

double	ft_atodou(const char *str)
{
	int		i;
	int		signal;
	double	number;
	i = 0;
	signal = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signal = -1;
		i++;
	}
	number = calc_double(&str[i]);
	return (number * signal);
}

double	calc_double(const char *str)
{
	double	integer_part;
	double	frac_part;
	double	div;
	int	i;
	
	i = 0;
	div = 1.0;
	integer_part = 0.0;
	frac_part = 0.0;
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '.')
	{
		integer_part = (integer_part * 10) + (str[i] - '0');
		i++;
	}
	if(str[i] == '.')
		i++;
	while(str[i] >= '0' && str[i] <= '9')
	{
		div = div / 10;
		frac_part = frac_part + (str[i] - 48) * div;
		i++;
	}
	return (integer_part + frac_part);
}

int	ft_strscmp(char *str1, char *str2)
{
	unsigned int	i;

	i = 0;
	while ((str1[i] != '\0' || str2[i] != '\0'))
	{
		if (str1[i] != str2[i])
			return (1);
		i++;
	}
	return (0);
}

void	ft_putstr_fd(char *str, int fd)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(fd, &str[i], 1);
		i++;
	}
}
