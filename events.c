/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 14:00:46 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/09 17:20:43 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_move(int x, int y, t_data *data)
{
	usleep(10);
	draw_julia(*data);
    mlx_string_put(data->mlx, data->win, 50, 50, 0, ft_itoa(x));
	mlx_string_put(data->mlx, data->win, 50, 100, 0, ft_itoa(y));
	if (x - 800 < 0)
		data->julia.cRe = -0.7 - x * 0.0001;
	else
		data->julia.cRe = -0.7 + x * 0.0001;
	if (y - 600 < 0)
		data->julia.cIm = 0.27015 - y * 0.0001;
	else
		data->julia.cIm = 0.27015 + y * 0.0001;
	return (0);
}

int	my_mouse_funct(int button, int x, int y, t_data *data)
{
//	(void)button;
	printf("%d %d %d\n", button, x, y);
	draw_julia(*data);
    mlx_string_put(data->mlx, data->win, 50, 50, 0, ft_itoa(x));
	mlx_string_put(data->mlx, data->win, 50, 100, 0, ft_itoa(y));
	if (x - 800 < 0)
		data->julia.cRe = -0.7 - x * 0.0001;
	else
		data->julia.cRe = -0.7 + x * 0.0001;
	if (y - 600 < 0)
		data->julia.cIm = 0.27015 - y * 0.0001;
	else
		data->julia.cIm = 0.27015 + y * 0.0001;
	return (0);
}

int	my_key_funct(int keycode, t_data *data)
{
	printf("keycode: %d\n", keycode);
	if (keycode == 123)
	{
		data->julia.cRe -= 0.01;
		draw_julia(*data);
	}
	if (keycode == 124)
	{
		data->julia.cRe += 0.01;
		draw_julia(*data);
	}
	if (keycode == 125)
	{
		data->julia.cIm -= 0.01;
		draw_julia(*data);
	}
	if (keycode == 126)
	{
		data->julia.cIm += 0.01;
		draw_julia(*data);
	}
	if (keycode == 53)
	{
		mlx_destroy_image(data->mlx, data->img.img_ptr);
		mlx_destroy_window(data->mlx, data->win);
		exit(EXIT_SUCCESS);
	}
	return (0);
}
