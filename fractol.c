/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 13:43:03 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/27 14:42:52 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_data(t_data *data, char *fractal, void *f(void *))
{
	data->win_width = 800;
	data->win_height = 600;
	data->julia.cre = -0.7;
	data->julia.cim = 0.27015;
	data->i = 0;
	data->i_max = 90;
	data->zoom = 1;
	data->movex = 0;
	data->movey = 0;
	data->pause = 0;
	data->fractal = fractal;
	data->f = f;
}

int			fractol(char *fractal, void *f(void *))
{
	t_data	data;

	if ((data.mlx = mlx_init()) == NULL)
		exit(EXIT_FAILURE);
	init_data(&data, fractal, f);
	if ((data.win = mlx_new_window(data.mlx, data.win_width, data.win_height,
		fractal)) == NULL)
		exit(EXIT_FAILURE);
	data.img.img_ptr = mlx_new_image(data.mlx, data.win_width, data.win_height);
	data.img.data = (int *)mlx_get_data_addr(data.img.img_ptr, &data.img.bpp,
		&data.img.size_l, &data.img.endian);
	data.f(&data);
	print_infos(&data);
	mlx_hook(data.win, 17, 1L << 17, f_destroy, &data);
	mlx_key_hook(data.win, my_key_funct, &data);
	mlx_mouse_hook(data.win, my_mouse_funct, &data);
	if (ft_strcmp(fractal, "Julia") == 0)
		mlx_hook(data.win, 6, 6, mouse_move, &data);
	mlx_loop(data.mlx);
	mlx_destroy_image(data.mlx, data.img.img_ptr);
	mlx_destroy_window(data.mlx, data.win);
	exit(EXIT_SUCCESS);
}
