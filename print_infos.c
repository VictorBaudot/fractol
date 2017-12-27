/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_infos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 13:58:05 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/27 14:35:29 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_infos(t_data *data)
{
	mlx_string_put(data->mlx, data->win, 30, 50, 0, "Iterations:");
	mlx_string_put(data->mlx, data->win, 150, 50, 0, ft_itoa(data->i_max));
	mlx_string_put(data->mlx, data->win, 200, 50, 0, "[-=]");
}
