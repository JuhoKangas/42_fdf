/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_controller_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkangas <jkangas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 19:54:42 by jkangas           #+#    #+#             */
/*   Updated: 2022/05/02 20:05:40 by jkangas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	change_elevation(int key, t_fdf *data)
{
	if (key == 30 && data->elevation < 2.5)
		data->elevation += 0.01;
	if (key == 33 && data->elevation > 0.01)
		data->elevation -= 0.01;
	mlx_clear_window(data->mlx, data->win);
	display_ui(data);
	ft_draw_map(data);
}
