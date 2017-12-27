/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 17:50:34 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/27 14:34:46 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	algo_julia(int max_iterations, int x, int y, t_data *data)
{
	double	tab[4];
	int		i;

	tab[0] = 1.5 * (x - data->win_width / 2) /
	(0.5 * data->zoom * data->win_width) + data->movex;
	tab[1] = (y - data->win_height / 2) /
	(0.5 * data->zoom * data->win_height) + data->movey;
	i = 0;
	while (i < max_iterations)
	{
		tab[2] = tab[0];
		tab[3] = tab[1];
		tab[0] = tab[2] * tab[2] - tab[3] * tab[3] + data->julia.cre;
		tab[1] = 2 * tab[2] * tab[3] + data->julia.cim;
		if ((tab[0] * tab[0] + tab[1] * tab[1]) > 4)
			break ;
		i++;
	}
	data->img.data[y * data->win_width + x] = get_color(i, sqrt(tab[0] * tab[0]
		+ tab[1] * tab[1]));
	x++;
}

void		*draw_julia(void *d)
{
	int		x;
	int		y;
	t_data	*data;

	y = 0;
	data = d;
	while (y < data->win_height)
	{
		x = 0;
		while (x < data->win_width)
		{
			algo_julia(data->i_max, x, y, data);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr, 0, 0);
	return (0);
}
