/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkangas <jkangas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 14:28:29 by jkangas           #+#    #+#             */
/*   Updated: 2022/05/02 19:09:15 by jkangas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	init_struct(t_fdf *data)
{
	data->zoom = 30;
	data->x_off = 500;
	data->y_off = 200;
	data->view = 0;
	data->color = rgb_to_int(1, 1, 1);
}

int	rgb_to_int(double r, double g, double b)
{
	int	color;

	color = 0;
	color |= (int)(b * 255);
	color |= (int)(g * 255) << 8;
	color |= (int)(r * 255) << 16;
	return (color);
}

int	key_hook(int key, t_fdf *data)
{
	if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
		move_fdf(key, data);
	if (key == 49)
		change_view(data);
	if (key == 24 || key == 27)
		zoom_view(key, data);
	if (key == 53)
		exit_fdf(data);
	if (key == 8)
		change_color(data);
	return (0);
}
