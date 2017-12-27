/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 14:00:46 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/27 14:51:17 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	f_destroy(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img.img_ptr);
	mlx_destroy_window(data->mlx, data->win);
	exit(EXIT_SUCCESS);
}

int	mouse_move(int x, int y, t_data *data)
{
	if (data->pause == 0)
	{
		if (x - data->win_width / 2 < 0)
			data->julia.cre = -0.7 - (x - data->win_width / 2) * 0.0001;
		else
			data->julia.cre = -0.7 + (x - data->win_width / 2) * 0.0001;
		if (y - data->win_height / 2 < 0)
			data->julia.cim = 0.27015 - (y - data->win_height / 2) * 0.0001;
		else
			data->julia.cim = 0.27015 + (y - data->win_height / 2) * 0.0001;
		data->f(data);
		print_infos(data);
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
	print_infos(data);
	return (0);
}

int	my_key_funct(int keycode, t_data *data)
{
	if (keycode == 53)
		f_destroy(data);
	if (keycode == 35)
		data->pause = (data->pause == 0) ? 1 : 0;
	if (keycode == 69)
		data->zoom *= 1.1;
	if (keycode == 78)
		data->zoom /= 1.1;
	if (keycode == 24)
		data->i_max += 20;
	if (keycode == 27)
		data->i_max -= 20;
	if (keycode == 123)
		data->movex -= 0.2 / data->zoom;
	if (keycode == 124)
		data->movex += 0.2 / data->zoom;
	if (keycode == 126)
		data->movey -= 0.2 / data->zoom;
	if (keycode == 125)
		data->movey += 0.2 / data->zoom;
	data->f(data);
	print_infos(data);
	return (0);
}
