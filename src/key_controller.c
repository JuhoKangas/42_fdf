/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_controller.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkangas <jkangas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 14:07:19 by jkangas           #+#    #+#             */
/*   Updated: 2022/04/28 15:35:34 by jkangas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	move_fdf(int key, t_fdf *data)
{
	if (key == UP)
		data->y_off -= 50;
	if (key == DOWN)
		data->y_off += 50;
	if (key == LEFT)
		data->x_off -= 50;
	if (key == RIGHT)
		data->x_off += 50;
	mlx_clear_window(data->mlx, data->win);
	ft_draw_map(data);
}

static void	change_view(t_fdf *data)
{
	if (data->view == 0)
	{
		data->view = 1;
		data->x_off = 700;
		data->y_off = 200;
	}
	else
	{
		data->view = 0;
		data->x_off = 300;
		data->y_off = 200;
	}
	mlx_clear_window(data->mlx, data->win);
	ft_draw_map(data);
}

static void	zoom_view(int key, t_fdf *data)
{
	if (key == 24)
		data->zoom += 10;
	if (key == 27)
		if (data->zoom > 10)
			data->zoom -= 10;
	mlx_clear_window(data->mlx, data->win);
	ft_draw_map(data);
}

int	key_hook(int key, t_fdf *data)
{
	if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
		move_fdf(key, data);
	if (key == 49)	
		change_view(data);
	if (key == 24 || key == 27)
		zoom_view(key, data);
	return (0);
}