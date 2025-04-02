/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltropina < ltropina@student.42urduliz.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 10:38:07 by ltropina          #+#    #+#             */
/*   Updated: 2024/07/28 11:12:51 by ltropina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

static int	is_space(char ch)
{
	if (ch == ' ' || (ch >= 9 && ch <= 13))
		return (1);
	return (0);
}

static void	ft_float(char *str, double *res, double divider)
{
	if (*str == '.')
	{
		str++;
		while (*str >= '0' && *str <= '9')
		{
			*res += (*str - '0') / divider;
			divider *= 10;
			str++;
		}
	}
}

double	ft_atof(char *str)
{
	int		sign;
	double	res;
	double	divider;

	sign = 1;
	res = 0;
	divider = 10;
	while (is_space(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		str++;
	}
	ft_float(str, &res, divider);
	return (sign * res);
}
