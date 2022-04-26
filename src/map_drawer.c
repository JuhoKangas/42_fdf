/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_drawer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkangas <jkangas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 18:29:29 by jkangas           #+#    #+#             */
/*   Updated: 2022/04/22 16:55:36 by jkangas          ###   ########.fr       */
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

static t_coord	ft_horizontal_line(int x, int y)
{
	t_coord	line;
	
	line.x1 = x;
	line.y1 = y;
	line.x2 = line.x1 + GRID;
	line.y2 = line.y1;

	return (line);
}

static t_coord	ft_vertical_line(int x, int y)
{
	t_coord	line;
	
	line.x1 = x;
	line.y1 = y;
	line.x2 = line.x1;
	line.y2 = line.y1 + GRID;

	return (line);
}

void	ft_draw_map(t_fdf *ptr)
{
	int		i;
	int		j;
	int		x_temp;
	int		y_temp;

	j = 0;
	y_temp = OFFSET;
	while (j < ptr->rows)
	{
		x_temp = OFFSET;
		i = 0;
		while (i < ptr->cols)
		{
			if (i++ < ptr->cols - 1)
				ft_dda(ft_horizontal_line(x_temp, y_temp), ptr);
			if (j < ptr->rows - 1)
				ft_dda(ft_vertical_line(x_temp, y_temp), ptr);
			x_temp += GRID;
		}
		j++;
		y_temp = OFFSET + j * GRID;
	}
}
