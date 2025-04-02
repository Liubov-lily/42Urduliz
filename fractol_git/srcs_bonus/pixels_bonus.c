/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltropina < ltropina@student.42urduliz.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 12:14:51 by ltropina          #+#    #+#             */
/*   Updated: 2024/07/28 13:12:27 by ltropina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol_bonus.h"

double	scalex(int x, t_mlx *mlx)
{
	return (x * mlx->scale / (WIDTH - 1) - mlx->scale / 2 + mlx->center_x);
}

double	scaley(int y, t_mlx *mlx)
{
	return (-y * mlx->scale / (HEIGHT - 1) + mlx->scale / 2 + mlx->center_y);
}

static int	color_set(int iter)
{
	double	r;
	double	g;
	double	b;
	int		color;

	r = sin(0.3 * (double)iter);
	g = sin(0.3 * (double)iter + 3) * 127 + 128;
	b = sin(0.3 * (double)iter + 3) * 127 + 128;
	color = ((int)(255.9 * r) << 16)
		+ ((int)(255.9 * g) << 8)
		+ ((int)(255.9 * b));
	return (color);
}

static void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->data + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

int	put_pixels(t_mlx *mlx)
{
	int	i;
	int	j;
	int	res;

	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			if (ft_strcmp(mlx->name, "julia") == 0)
				res = julia(scalex(i, mlx), scaley(j, mlx), mlx);
			else
				res = mandelbrot(scalex(i, mlx), scaley(j, mlx), mlx);
			if (res == mlx->max_iter)
				my_mlx_pixel_put(&mlx->img, i, j, 0);
			else
				my_mlx_pixel_put(&mlx->img, i, j, color_set(res));
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->img.img_ptr, 0, 0);
	return (0);
}
