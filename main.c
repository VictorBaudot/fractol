/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 09:43:26 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/22 11:43:17 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	tab_init(t_fractals **tab)
{
	t_fractals	*tmp;

	tmp = *tab;
	tmp[0].fractal = "Julia";
	tmp[0].f = draw_julia;
	tmp[1].fractal = "Mandelbrot";
	tmp[1].f = draw_mandelbrot;
	tmp[2].fractal = "Burning ship";
	tmp[2].f = draw_burning_ship;
	tmp[3].fractal = 0;
	tmp[3].f = NULL;
}

int			main(int ac, char **av)
{
	int			i;
	t_fractals	*tab;

	i = -1;
	if (ac == 2)
	{
		tab = (t_fractals *)malloc(sizeof(t_fractals) * 4);
		tab_init(&tab);
		while (++i < 3)
			if (ft_strcmp(av[1], tab[i].fractal) == 0)
				fractol(tab[i].fractal, tab[i].f);
		free(tab);
	}
	print_usage();
	return (EXIT_SUCCESS);
}
