/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_newton.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 11:58:46 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/12 11:59:02 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	*draw_newton(void *d)
{
	double newRe, newIm, oldRe, oldIm;
	int maxIterations = 256;
	double pr, pi;
	int color;
	int x;
	int y;
	int i;
	t_data *data = d;

	y = 0;
	while (y < data->win_height)
	{
		x = 0;
		while (x < data->win_width)
		{
			pr = 1.5 * (x - data->win_width / 2) / (0.5 * data->zoom * data->win_width) + data->moveX - 0.5;
			pi = (y - data->win_height / 2) / (0.5 * data->zoom * data->win_height) + data->moveY;
			newRe = newIm = oldRe = oldIm = 0;
			i = 0;
			while (i < maxIterations)
			{
				oldRe = newRe;
				oldIm = newIm;
				newRe = oldRe * oldRe - oldIm * oldIm + pr;
				newIm = 2 * oldRe * oldIm + pi;
				if ((newRe * newRe + newIm * newIm) > 4)
					break;
				i++;
			}
			color = ((255 - 2.5 * i) >= 0) ? (int)(255 - 2.5 * i) : 256;
			data->img.data[y * data->win_width + x] = color;
		x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr, 0, 0);
	return (0);
}
