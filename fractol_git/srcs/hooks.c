/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltropina < ltropina@student.42urduliz.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 12:11:51 by ltropina          #+#    #+#             */
/*   Updated: 2024/07/28 15:04:49 by ltropina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

int	mouse_hook(int mouse_code, int x, int y, t_mlx *mlx)
{
	(void)x;
	(void)y;
	if (mouse_code == Button4)
	{
		mlx->scale *= 0.9;
		mlx->max_iter *= 1.2;
	}
	else if (mouse_code == Button5)
	{
		mlx->scale /= 0.9;
		mlx->max_iter /= 1.2;
		if (mlx->max_iter < 40)
			mlx->max_iter = 40;
	}
	return (0);
}

int	key_hook(int key_code, t_mlx *mlx)
{
	if (key_code == XK_Escape)
	{
		destroy_all(mlx);
		exit (0);
	}
	return (0);
}

/*int	key_hook(int key_code, t_mlx *mlx)
{
	if (key_code == XK_Escape)
	{
		destroy_all(mlx);
		exit (0);
	}
	else if (key_code == XK_Left)
		mlx->center_x += 0.1;
	else if (key_code == XK_Right)
		mlx->center_x -= 0.1;
	else if (key_code == XK_Up)
		mlx->center_y -= 0.1;
	else if (key_code == XK_Down)
		mlx->center_y += 0.1;
	return (0);
}*/
/*int	mouse_hook(int mouse_code, int x, int y, t_mlx *mlx)
{
	if (ft_strcmp(mlx->name, "julia") == 0)
	{
		mlx->juliax = scalex(x, mlx);
		mlx->juliay = scaley(y, mlx);
	}
	else
	{
		if (mouse_code == Button4)
		{
			mlx->scale *= 0.9;
			mlx->max_iter *= 1.2;
			mlx->center_x = scalex(x, mlx);
			mlx->center_y = scaley(y, mlx);
		}
		else if (mouse_code == Button5)
		{
			mlx->scale /= 0.9;
			mlx->max_iter /= 1.2;
			mlx->center_x = scalex(x, mlx);
			mlx->center_y = scaley(y, mlx);
		}
	}
	return (0);
}*/