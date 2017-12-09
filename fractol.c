/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 13:43:03 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/09 17:16:16 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_data	init_data(t_data data)
{
	data.win_width = 1600;
	data.win_height = 1200;
	data.julia.cRe = -0.7;
	data.julia.cIm = 0.27015;
	return (data);
}

int				fractol(char *fractale)
{
	t_data	data;
	int		i;

	i = -1;
	if ((data.mlx = mlx_init()) == NULL)
		exit(EXIT_FAILURE);
	data = init_data(data);
	if ((data.win = mlx_new_window(data.mlx, data.win_width, data.win_height,
		fractale)) == NULL)
		exit(EXIT_FAILURE);
	data.img.img_ptr = mlx_new_image(data.mlx, data.win_width, data.win_height);
	data.img.data = (int *)mlx_get_data_addr(data.img.img_ptr, &data.img.bpp,
		&data.img.size_l, &data.img.endian);
	(ft_strcmp(fractale, "Mandelbrot") == 0) ? draw_mandelbrot(data) : draw_julia(data);
	mlx_key_hook(data.win, my_key_funct, &data);
	mlx_mouse_hook(data.win, my_mouse_funct, &data);
	mlx_hook(data.win, 6, 6, mouse_move, &data);
	mlx_loop(data.mlx);
	mlx_destroy_image(data.mlx, data.img.img_ptr);
	mlx_destroy_window(data.mlx, data.win);
	exit(EXIT_SUCCESS);
}
