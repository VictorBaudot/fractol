/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 17:50:34 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/07 18:35:07 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw(t_data data)
{
	// on définit la zone que l'on dessine. Ici, la fractale en entière
	double x1 = -2.1;
	// double x2 = 0.6;
	double y1 = -1.2;
	// double y2 = 1.2;
	double zoom = 100; // pour une distance de 1 sur le plan, on a 100 pixel sur l'image
	double iteration_max = 50;

	// on calcule la taille de l'image :
	// double image_x = (x2 - x1) * zoom;
	// double image_y = (y2 - y1) * zoom;

	int x;
	int y;

	x = 0;
	while (x < data.win_width)
	{
		y = 0;
		while (y < data.win_height)
		{
			double c_r = x / zoom + x1;
			double c_i = y / zoom + y1;
			double z_r = 0;
			double z_i = 0;
			double i = 0;

			while (z_r*z_r + z_i*z_i < 4 && i < iteration_max)
			{
				double tmp = z_r;
				z_r = z_r*z_r - z_i*z_i + c_r;
				z_i = 2*z_i*tmp + c_i;
				i = i+1;
			}
			if (i == iteration_max)
				data.img.data[y * data.win_width + x] = 0xFFFFFF;
			y++;
		}
		x++;
	}
}
