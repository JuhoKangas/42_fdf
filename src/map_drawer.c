/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_drawer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkangas <jkangas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 18:29:29 by jkangas           #+#    #+#             */
/*   Updated: 2022/04/28 14:05:40 by jkangas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// ISOMETRIC ALGORITHMS
// 30 degrees = 0.523598776 rad
// ptr->x = (x - y) * cos(30)
// ptr->y = -z + (x + y) * sin(30)

static void	ft_dda(t_coord line, t_fdf *ptr)
{
	int		steps;
	float	x_incr;
	float	y_incr;
	float	x;
	float	y;

	line.delta_x = line.x2 - line.x1;
	line.delta_y = line.y2 - line.y1;
	if (ft_abs(line.delta_x) > ft_abs(line.delta_y))
		steps = fabs(line.delta_x);
	else
		steps = fabs(line.delta_y);
	x_incr = line.delta_x / (float) steps;
	y_incr = line.delta_y / (float) steps;
	x = line.x1;
	y = line.y1;
	while (steps > -1)
	{
		mlx_pixel_put(ptr->mlx, ptr->win, x, y, rgb_to_int(1, 1, 1));
		x += x_incr;
		y += y_incr;
		steps--;
	}
}

static void	isometric(int *x, int *y, int z)
{
	*x = (*x - *y) * cos(0.523598776);
	*y = (*x + *y) * sin(0.523598776) - (z * 5);
}

static t_coord	ft_horizontal_line(int x, int y, t_fdf *ptr)
{
	t_coord	line;
	int		temp_x;
	int		temp_y;

	temp_x = x;
	temp_y = y;
	temp_x = x * ptr->zoom;
	temp_y = y * ptr->zoom;
	if (ptr->view == 1)
		isometric(&temp_x, &temp_y, ptr->map[y][x]);
	line.x1 = temp_x + ptr->x_off;
	line.y1 = temp_y + ptr->y_off;
	temp_x = x * ptr->zoom;
	temp_y = y * ptr->zoom;
	temp_x += ptr->zoom;
	if (ptr->view == 1)
		isometric(&temp_x, &temp_y, ptr->map[y][x + 1]);
	line.x2 = temp_x + ptr->x_off;
	line.y2 = temp_y + ptr->y_off;
	return (line);
}

static t_coord	ft_vertical_line(int x, int y, t_fdf *ptr)
{
	t_coord	line;
	int		temp_x;
	int		temp_y;

	temp_x = x;
	temp_y = y;
	temp_x = x * ptr->zoom;
	temp_y = y * ptr->zoom;
	if (ptr->view == 1)
		isometric(&temp_x, &temp_y, ptr->map[y][x]);
	line.x1 = temp_x + ptr->x_off;
	line.y1 = temp_y + ptr->y_off;
	temp_x = x * ptr->zoom;
	temp_y = y * ptr->zoom;
	temp_y += ptr->zoom;
	if (ptr->view == 1)
		isometric(&temp_x, &temp_y, ptr->map[y + 1][x]);
	line.x2 = temp_x + ptr->x_off;
	line.y2 = temp_y + ptr->y_off;
	return (line);
}

void	ft_draw_map(t_fdf *ptr)
{
	int		x;
	int		y;

	ptr->view = 1;
	ptr->x_off = 600;
	ptr->y_off = 200;
	ptr->zoom = 70;
	y = 0;
	while (y < ptr->rows)
	{
		x = 0;
		while (x < ptr->cols)
		{
			if (x < ptr->cols - 1)
				ft_dda(ft_horizontal_line(x, y, ptr), ptr);
			if (y < ptr->rows - 1)
				ft_dda(ft_vertical_line(x, y, ptr), ptr);
			x++;
		}
		y++;
	}
}
