/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 09:58:46 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/27 15:00:11 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <pthread.h>
# include "libft.h"

typedef struct	s_julia
{
	double		cre;
	double		cim;
}				t_julia;

union			u_color
{
	unsigned int	number;
	unsigned char	channels[4];
};

typedef struct	s_img
{
	void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef struct	s_data
{
	void		*mlx;
	void		*win;
	t_julia		julia;
	t_img		img;
	int			win_width;
	int			win_height;
	int			i;
	int			i_max;
	double		zoom;
	double		movex;
	double		movey;
	int			pause;
	char		*fractal;
	void		*(*f)(void *);
}				t_data;

typedef struct	s_fractales
{
	char		*fractal;
	void		*(*f)(void *);
}				t_fractals;

int				f_destroy(t_data *data);
int				get_color(int i, int zn);
void			*draw_julia(void *data);
void			*draw_burning_ship(void *d);
void			*draw_mandelbrot(void *data);
int				mouse_move(int x, int y, t_data *data);
int				my_mouse_funct(int button, int x, int y, t_data *data);
int				my_key_funct(int keycode, t_data *data);
int				fractol(char *fractal, void *(*f)(void *));
void			ft_error(void);
void			print_usage(void);

#endif
