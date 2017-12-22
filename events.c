/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 14:00:46 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/22 11:46:27 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_move(int x, int y, t_data *data)
{
	if (data->pause == 0)
	{
		if (x - data->win_width / 2 < 0)
			data->julia.cRe = -0.7 - (x - data->win_width / 2) * 0.0001;
		else
			data->julia.cRe = -0.7 + (x - data->win_width / 2) * 0.0001;
		if (y - data->win_height / 2 < 0)
			data->julia.cIm = 0.27015 - (y - data->win_height / 2) * 0.0001;
		else
			data->julia.cIm = 0.27015 + (y - data->win_height / 2) * 0.0001;
		data->f(data);
		mlx_string_put(data->mlx, data->win, 30, 50, 0, "x:");
		mlx_string_put(data->mlx, data->win, 50, 50, 0, ft_itoa(x));
		mlx_string_put(data->mlx, data->win, 30, 100, 0, "y:");
		mlx_string_put(data->mlx, data->win, 50, 100, 0, ft_itoa(y));
	}
	return (0);
}

int	my_mouse_funct(int button, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (button == 4)
		data->zoom *= 1.1;
	if (button == 5)
		data->zoom /= 1.1;
	data->f(data);
	return (0);
}

int	my_key_funct(int keycode, t_data *data)
{
	if (keycode == 53)
	{
		mlx_destroy_image(data->mlx, data->img.img_ptr);
		mlx_destroy_window(data->mlx, data->win);
		exit(EXIT_SUCCESS);
	}
	if (keycode == 35)
		data->pause = (data->pause == 0) ? 1 : 0;
	if (keycode == 69)
		data->zoom *= 1.1;
	if (keycode == 78)
		data->zoom /= 1.1;
	if (keycode == 123)
		data->moveX -= 0.2 / data->zoom;
	if (keycode == 124)
		data->moveX += 0.2 / data->zoom;
	if (keycode == 126)
		data->moveY -= 0.2 / data->zoom;
	if (keycode == 125)
		data->moveY += 0.2 / data->zoom;
	data->f(data);
	return (0);
}
