/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 17:50:34 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/09 11:25:26 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_julia(t_data data)
{
	//each iteration, it calculates: new = old*old + c, where c is a constant and old starts at current pixel
//	double cRe, cIm;           //real and imaginary part of the constant c, determinate shape of the Julia Set
	double newRe, newIm, oldRe, oldIm;   //real and imaginary parts of new and old
	double zoom = 1, moveX = 0, moveY = 0; //you can change these to zoom and change position
	int maxIterations = 100; //after how much iterations the function should stop
	int color;
	int x;
	int y;
	int i;

	y = 0;
	//pick some values for the constant c, this determines the shape of the Julia Set
	//cRe = data.julia.cRe;
	//cIm = data.julia.cIm;
	//loop through every pixel
	while (y < data.win_height)
	{
		x = 0;
		while (x < data.win_width)
		{
			newRe = 1.5 * (x - data.win_width / 2) / (0.5 * zoom * data.win_width) + moveX;
			newIm = (y - data.win_height / 2) / (0.5 * zoom * data.win_height) + moveY;
			//i will represent the number of iterations
			//start the iteration process
			i = 0;
			while (i < maxIterations)
			{
				//remember value of previous iteration
				oldRe = newRe;
				oldIm = newIm;
				//the actual iteration, the real and imaginary part are calculated
				newRe = oldRe * oldRe - oldIm * oldIm + data.julia.cRe;
				newIm = 2 * oldRe * oldIm + data.julia.cIm;
				//if the point is outside the circle with radius 2: stop
				if ((newRe * newRe + newIm * newIm) > 4)
					break;
				i++;
			}
			//use color model conversion to get rainbow palette, make brightness black if maxIterations reached
			color = ((255 - 2.5 * i) >= 0) ? (int)(255 - 2.5 * i) : 256;
			//printf("%d ", color);
			//draw the pixel
			data.img.data[y * data.win_width + x] = color;
		x++;
	  }
	  y++;
  }
  mlx_put_image_to_window(data.mlx, data.win, data.img.img_ptr, 0, 0);
 // mlx_string_put(data.mlx, data.win, 50, 50, 0, ft_itoa(data.julia.cRe));
}
