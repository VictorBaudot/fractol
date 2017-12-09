/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 09:43:26 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/08 06:14:10 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	(void)av;
	if (ac == 2)
	{
		if (ft_strcmp(av[1], "Mandelbrot") != 0 && ft_strcmp(av[1], "Julia") != 0)
			print_usage();
		else
			fractol(av[1]);
	}
	else
		print_usage();
	return (EXIT_SUCCESS);
}
