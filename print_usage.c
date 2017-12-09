/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_usage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 14:04:58 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/08 05:54:17 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_error(void)
{
	ft_putstr("error.\n");
	exit(EXIT_FAILURE);
}

void	print_usage(void)
{
	ft_putstr("usage: ./fractol [Mandelbrot] [Julia]\n");
	exit(EXIT_FAILURE);
}
