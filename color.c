/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 13:17:16 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/27 14:52:00 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_color(int i, int zn)
{
	union u_color	c;
	double			continuous_index;

	continuous_index = i + 1 - (log(2) / zn) / log(2);
	c.channels[0] = (unsigned char)(sin(0.016 * continuous_index + 4)
	* 127.5 + 127.5);
	c.channels[1] = (unsigned char)(sin(0.013 * continuous_index + 2)
	* 127.5 + 127.5);
	c.channels[2] = (unsigned char)(sin(0.01 * continuous_index + 1)
	* 127.5 + 127.5);
	c.channels[3] = 0;
	return (c.number);
}
