/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dif_fractals.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltropina < ltropina@student.42urduliz.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 11:05:57 by ltropina          #+#    #+#             */
/*   Updated: 2024/07/28 11:12:33 by ltropina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

int	julia(double x, double y, t_mlx *mlx)
{
	int		iter;
	double	x0;
	double	y0;
	double	oldx;

	iter = 0;
	x0 = mlx->juliax;
	y0 = mlx->juliay;
	x = x;
	y = y;
	while (x * x + y * y < 4 && iter < mlx->max_iter)
	{
		oldx = x;
		x = x * x - y * y + x0;
		y = 2 * oldx * y + y0;
		iter++;
	}
	return (iter);
}

int	mandelbrot(double x, double y, t_mlx *mlx)
{
	int		iter;
	double	x0;
	double	y0;
	double	oldx;

	iter = 0;
	x0 = x;
	y0 = y;
	x = 0;
	y = 0;
	while (x * x + y * y < 4 && iter < mlx->max_iter)
	{
		oldx = x;
		x = x * x - y * y + x0;
		y = 2 * oldx * y + y0;
		iter++;
	}
	return (iter);
}
