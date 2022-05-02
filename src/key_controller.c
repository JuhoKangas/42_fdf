/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_controller.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkangas <jkangas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 14:07:19 by jkangas           #+#    #+#             */
/*   Updated: 2022/05/02 19:12:34 by jkangas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	move_fdf(int key, t_fdf *data)
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
	display_ui(data);
	ft_draw_map(data);
}

void	change_view(t_fdf *data)
{
	if (data->view < 2)
		data->view++;
	else
		data->view = 0;
	if (data->view == 0)
	{
		data->x_off = 500;
		data->y_off = 200;
	}
	if (data->view == 1)
	{
		data->x_off = 900;
		data->y_off = 200;
		data->angle = 0.523598776;
	}
	if (data->view == 2)
	{
		data->x_off = 700;
		data->y_off = 200;
		data->angle = 1.04719755;
	}
	mlx_clear_window(data->mlx, data->win);
	display_ui(data);
	ft_draw_map(data);
}

void	zoom_view(int key, t_fdf *data)
{
	if (key == 24)
		data->zoom += 10;
	if (key == 27)
		if (data->zoom > 10)
			data->zoom -= 10;
	mlx_clear_window(data->mlx, data->win);
	display_ui(data);
	ft_draw_map(data);
}

void	change_color(t_fdf *data)
{
	if (data->color == rgb_to_int(1, 1, 1))
		data->color = rgb_to_int(0, 1, 1);
	else if (data->color == rgb_to_int(0, 1, 1))
		data->color = rgb_to_int(1, 0, 0);
	else
		data->color = rgb_to_int(1, 1, 1);
	mlx_clear_window(data->mlx, data->win);
	display_ui(data);
	ft_draw_map(data);
}

void	exit_fdf(t_fdf *data)
{
	mlx_destroy_window(data->mlx, data->win);
	if (data)
		exit (0);
}
