/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_drawer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkangas <jkangas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 18:29:29 by jkangas           #+#    #+#             */
/*   Updated: 2022/04/14 19:04:07 by jkangas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "mlx.h"

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
	while (steps)
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
	ft_draw_line(100, 100, 200, 200, ptr);
}