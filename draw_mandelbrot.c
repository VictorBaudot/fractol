/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mandelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 17:50:34 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/27 14:34:37 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	algo_mandelbrot(int max_iterations, t_data *data, int x, int y)
{
	double	tab[6];
	int		i;

	tab[4] = 1.5 * (x - data->win_width / 2) /
	(0.5 * data->zoom * data->win_width) + data->movex - 0.5;
	tab[5] = (y - data->win_height / 2) /
	(0.5 * data->zoom * data->win_height) + data->movey;
	i = -1;
	while (++i < 4)
		tab[i] = 0;
	i = 0;
	while (i < max_iterations)
	{
		tab[2] = tab[0];
		tab[3] = tab[1];
		tab[0] = tab[2] * tab[2] - tab[3] * tab[3] + tab[4];
		tab[1] = 2 * tab[2] * tab[3] + tab[5];
		if ((tab[0] * tab[0] + tab[1] * tab[1]) > 4)
			break ;
		i++;
	}
	data->img.data[y * data->win_width + x] = get_color(i, sqrt(tab[0] * tab[0]
		+ tab[1] * tab[1]));
}

void		*draw_mandelbrot(void *d)
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
			algo_mandelbrot(data->i_max, data, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr, 0, 0);
	return (0);
}
