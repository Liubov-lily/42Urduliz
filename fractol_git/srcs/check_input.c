/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltropina < ltropina@student.42urduliz.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 10:38:26 by ltropina          #+#    #+#             */
/*   Updated: 2024/07/28 11:16:29 by ltropina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

static int	ft_correct_num_input(char *str)
{
	while (*str)
	{
		if (!(*str == '-' || *str == '+' || *str == '.'
				|| (*str >= '0' && *str <= '9')))
			return (0);
		str++;
	}
	return (1);
}

static void	ft_str_to_lower(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] - ('A' - 'a');
		i++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	ft_check_input(int argc, char **argv)
{
	double	x;
	double	y;
	char	*name;

	if (argc < 2)
		return (1);
	ft_str_to_lower(argv[1]);
	name = argv[1];
	if (ft_strcmp(name, "julia") == 0 && argc == 4)
	{
		if (!ft_correct_num_input(argv[2]))
			return (1);
		if (!ft_correct_num_input(argv[3]))
			return (1);
		x = ft_atof(argv[2]);
		y = ft_atof(argv[3]);
		if (!(x >= -2 && x <= 2 && y >= -2 && y <= 2))
			return (2);
	}
	else if (ft_strcmp(name, "mandelbrot") == 0 && argc == 2)
		return (0);
	else
		return (1);
	return (0);
}
