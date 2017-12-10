/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 14:00:46 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/10 17:37:34 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_wheel(int x, int y, t_data data)
{
	(void)data;
	printf("Mouse wheel %d %d\n", x, y);
	return (0);
}

int	mouse_move(int x, int y, t_data *data)
{
//	usleep(10);
	if (x - data->win_width / 2 < 0)
		data->julia.cRe = -0.7 - (x - data->win_width / 2) * 0.0001;
	else
		data->julia.cRe = -0.7 + (x - data->win_width / 2) * 0.0001;
	if (y - data->win_height / 2 < 0)
		data->julia.cIm = 0.27015 - (y - data->win_height / 2) * 0.0001;
	else
		data->julia.cIm = 0.27015 + (y - data->win_height / 2) * 0.0001;
	draw_julia(data);
	//printf("%f %f\n", data->julia.cRe, data->julia.cIm);
	mlx_string_put(data->mlx, data->win, 30, 50, 0, "x:");
	mlx_string_put(data->mlx, data->win, 50, 50, 0, ft_itoa(x));
	mlx_string_put(data->mlx, data->win, 30, 100, 0, "y:");
	mlx_string_put(data->mlx, data->win, 50, 100, 0, ft_itoa(y));
/*	pthread_t tid;

//	usleep(10);
	data->i++;
	if (x - data->win_width / 2 < 0)
		data->julia.cRe = -0.7 - (x - data->win_width / 2) * 0.0001;
	else
		data->julia.cRe = -0.7 + (x - data->win_width / 2) * 0.0001;
	if (y - data->win_height / 2 < 0)
		data->julia.cIm = 0.27015 - (y - data->win_height / 2) * 0.0001;
	else
		data->julia.cIm = 0.27015 + (y - data->win_height / 2) * 0.0001;
	if (pthread_create(&(tid), NULL, draw_julia, data) != 0)
		printf("\ncan't create thread");
	//printf("%f %f\n", data->julia.cRe, data->julia.cIm);
	if (pthread_join(tid, NULL)) {
		perror("pthread_join");
		return EXIT_FAILURE;
	}
	mlx_string_put(data->mlx, data->win, 30, 50, 0, "x:");
	mlx_string_put(data->mlx, data->win, 50, 50, 0, ft_itoa(x));
	mlx_string_put(data->mlx, data->win, 30, 100, 0, "y:");
	mlx_string_put(data->mlx, data->win, 50, 100, 0, ft_itoa(y));*/
	return (0);
}

int	my_mouse_funct(int button, int x, int y, t_data *data)
{
		printf("%d %d %d\n", button, x, y);
/*	draw_julia(*data);
    mlx_string_put(data->mlx, data->win, 50, 50, 0, ft_itoa(x));
	mlx_string_put(data->mlx, data->win, 50, 100, 0, ft_itoa(y));
	if (x - 800 < 0)
		data->julia.cRe = -0.7 - x * 0.0001;
	else
		data->julia.cRe = -0.7 + x * 0.0001;
	if (y - 600 < 0)
		data->julia.cIm = 0.27015 - y * 0.0001;
	else
		data->julia.cIm = 0.27015 + y * 0.0001;*/
	if (button == 4)// +
		data->zoom += 1;
	if (button == 5)// -
		data->zoom -= 1;
	draw_julia(data);
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
	if (keycode == 69)// +
		data->zoom += 0.2;
	if (keycode == 78)// -
		data->zoom -= 0.2;
	if (keycode == 67)// *
		data->zoom += 10;
	if (keycode == 75)// /
		data->zoom -= 10;
	if (keycode == 123)// Left
		data->moveX -= 0.2 / data->zoom;
	if (keycode == 124)// Right
		data->moveX += 0.2 / data->zoom;
	if (keycode == 126)// Up
		data->moveY -= 0.2 / data->zoom;
	if (keycode == 125)// Down
		data->moveY += 0.2 / data->zoom;
	draw_julia(data);
	return (0);
}
