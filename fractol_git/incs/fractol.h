/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltropina < ltropina@student.42urduliz.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:45:31 by ltropina          #+#    #+#             */
/*   Updated: 2024/07/28 13:16:55 by ltropina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>

# define WIDTH 800
# define HEIGHT 800
# define XMIN -2
# define XMAX 2
# define YMIN -2
# define YMAX 2

# define ZOOM_IN 65451
# define ZOOM_OUT 65453

typedef struct s_img
{
	void	*img_ptr;
	char	*data;
	int		bpp;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_mlx
{
	char	*name;
	void	*mlx_ptr;
	void	*win;
	t_img	img;
	int		max_iter;
	double	center_x;
	double	center_y;
	double	juliax;
	double	juliay;
	double	scale;
}	t_mlx;

void	init_mlx(t_mlx *mlx);

int		julia(double x, double y, t_mlx *mlx);
int		mandelbrot(double x, double y, t_mlx *mlx);

double	ft_atof(char *str);

int		ft_check_input(int argc, char **argv);
int		ft_strcmp(char *s1, char *s2);

int		mouse_hook(int mouse_code, int x, int y, t_mlx *mlx);
int		key_hook(int key_code, t_mlx *mlx);

double	scalex(int x, t_mlx *mlx);
double	scaley(int y, t_mlx *mlx);
int		put_pixels(t_mlx *mlx);

void	destroy_all(t_mlx	*mlx);

#endif