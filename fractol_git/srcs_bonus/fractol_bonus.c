/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltropina < ltropina@student.42urduliz.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 10:31:46 by ltropina          #+#    #+#             */
/*   Updated: 2024/07/28 13:16:18 by ltropina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol_bonus.h"

void	destroy_all(t_mlx	*mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->img.img_ptr);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win);
	mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->mlx_ptr);
}

int	close_window(t_mlx *mlx)
{
	destroy_all(mlx);
	exit(0);
}

void	ft_printstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	if (ft_check_input(argc, argv) != 0)
	{
		ft_printstr("Input data: Mandelbrot or Julia x y [-2, 2]");
		return (1);
	}
	mlx.name = argv[1];
	if (ft_strcmp(mlx.name, "julia") == 0)
	{
		mlx.juliax = ft_atof(argv[2]);
		mlx.juliay = ft_atof(argv[3]);
	}
	init_mlx(&mlx);
	put_pixels(&mlx);
	mlx_key_hook(mlx.win, key_hook, &mlx);
	mlx_mouse_hook(mlx.win, mouse_hook, &mlx);
	mlx_hook(mlx.win, 17, 0, close_window, &mlx);
	mlx_loop_hook(mlx.mlx_ptr, put_pixels, &mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}

/*void	my_mlx_pixel_put(t_img *img, int x, int y, int iter)
{
	char	*dst;
	
	dst = img->data + (y * img->line_length + x * (img->bpp/ 8));
	*(unsigned char *)dst = iter % 6 * 42;//blue;
	*(unsigned char *)(dst + 1) = iter % 4 * 33;//iter  % 2 * 33;green
	*(unsigned char *)(dst + 2) = iter % 3 * 66;//256 - iter  % 4 * 44;red
	*(unsigned char *)(dst + 3) = 0;//iter % 3 * 128; transperenty
}*/
/*int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	void	*mlx_image;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "Image");
	mlx_image = mlx_new_image(mlx, WIDTH, HEIGHT);
	mlx_put_image_to_window(mlx, mlx_win, mlx_image, 0, 0);
	mlx_pixel_put(mlx, mlx_win, 0, 0, 0xFFFFFF);
	mlx_key_hook(mlx_win, deal_key, );
	mlx_loop_hook()
	mlx_loop(mlx);
	mlx_destroy_window(mlx, mlx_win);
	return (0);
}*/
