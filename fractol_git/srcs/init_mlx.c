/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltropina < ltropina@student.42urduliz.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 12:46:33 by ltropina          #+#    #+#             */
/*   Updated: 2024/07/28 12:55:42 by ltropina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

static void	error_message_fail_create(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	init_mlx(t_mlx *mlx)
{
	mlx->max_iter = 50;
	mlx->scale = XMAX - XMIN;
	mlx->center_x = 0;
	mlx->center_y = 0;
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		error_message_fail_create("Failed connection to mlx");
	mlx->win = mlx_new_window(mlx->mlx_ptr, WIDTH, HEIGHT, mlx->name);
	if (!mlx->win)
	{
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
		error_message_fail_create("Can not create window");
	}
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, WIDTH, HEIGHT);
	if (!mlx->img.img_ptr)
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->win);
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
		error_message_fail_create("Can not create image");
	}
	mlx->img.data = mlx_get_data_addr(mlx->img.img_ptr, &mlx->img.bpp,
			&mlx->img.line_length, &mlx->img.endian);
}
