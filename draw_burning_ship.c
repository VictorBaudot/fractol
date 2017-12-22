/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_burning_ship.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 11:58:46 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/22 12:50:33 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	algo_burning_ship(int max_iterations, t_data *data, int x, int y)
{
	double	tab[6];
	int		i;
	int		color;

	tab[4] = 1.5 * (x - data->win_width / 2) /
	(0.5 * (data->zoom / 1.2) * data->win_width) + data->moveX - 0.5;
	tab[5] = (y - data->win_height / 2) /
	(0.5 * (data->zoom / 1.2) * data->win_height) + data->moveY - 0.5;
	i = -1;
	while (++i < 4)
		tab[i] = 0;
	i = 0;
	while (i < max_iterations)
	{
		tab[2] = fabs(tab[0]);
		tab[3] = fabs(tab[1]);
		tab[0] = tab[2] * tab[2] - tab[3] * tab[3] + tab[4];
		tab[1] = 2 * tab[2] * tab[3] + tab[5];
		if ((tab[0] * tab[0] + tab[1] * tab[1]) > 4)
			break ;
		i++;
	}
	color = ((255 - 2.5 * i) >= 0) ? (int)(255 - 2.5 * i) : 256;
	data->img.data[y * data->win_width + x] = color;
}

void		*draw_burning_ship(void *d)
{
	int		x;
	int		y;
	t_data	*data;

	data = d;
	y = 0;
	while (y < data->win_height)
	{
		x = 0;
		while (x < data->win_width)
		{
			algo_burning_ship(256, data, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr, 0, 0);
	return (0);
}
