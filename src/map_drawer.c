/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_drawer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkangas <jkangas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 18:29:29 by jkangas           #+#    #+#             */
/*   Updated: 2022/04/21 14:00:23 by jkangas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// ISOMETRIC ALGORITHMS
// 30 degrees = 0.523598776 rad
// ptr->x = (x - y) * cos(30)
// ptr->y = -z + (x + y) * sin(30)

static void	ft_dda(t_fdf *ptr)
{
	int		steps;
	float	x_incr;
	float	y_incr;
	float	x;
	float	y;

	ptr->delta_x = ptr->x2 - ptr->x1;
	ptr->delta_y = ptr->y2 - ptr->y1;
	if (ft_abs(ptr->delta_x) > ft_abs(ptr->delta_y))
		steps = fabs(ptr->delta_x);
	else
		steps = fabs(ptr->delta_y);
	x_incr = ptr->delta_x / (float) steps;
	y_incr = ptr->delta_y / (float) steps;
	x = ptr->x1;
	y = ptr->y1;
	while (steps > -1)
	{
		mlx_pixel_put(ptr->mlx, ptr->win, x, y, rgb_to_int(1, 1, 1));
		x += x_incr;
		y += y_incr;
		steps--;
	}
}

static void	ft_draw_line(int x1, int y1, int x2, int y2, t_fdf *ptr)
{
	ptr->x1 = x1;
	ptr->x2 = x2;
	ptr->y1 = y1;
	ptr->y2 = y2;

	ft_dda(ptr);
}

void	ft_draw_map(t_fdf *ptr)
{
	int	i;
	int	j;
	int	x_temp;
	int	y_temp;

	j = 0;
	y_temp = OFFSET;
	while (j < ptr->rows)
	{
		x_temp = OFFSET;
		i = 0;
		while (++i < ptr->cols)
		{
			ft_draw_line(x_temp, y_temp, x_temp + GRID, y_temp, ptr);
			if (j < ptr->rows - 1)
				ft_draw_line(x_temp, y_temp, x_temp, y_temp + GRID, ptr);
			x_temp += GRID;
		}
		if (j < ptr->rows - 1)
			ft_draw_line(x_temp, y_temp, x_temp, y_temp + GRID, ptr);
		j++;
		y_temp = OFFSET + j * GRID;
	}
}
