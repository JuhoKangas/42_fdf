/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkangas <jkangas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:23:07 by jkangas           #+#    #+#             */
/*   Updated: 2022/04/01 14:58:51 by jkangas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"	
#include "../includes/fdf.h"

int rgb_to_int(double r, double g, double b)
{
    int color = 0;
    color |= (int)(b * 255);
    color |= (int)(g * 255) << 8;
    color |= (int)(r * 255) << 16;
    return (color);
}

void	ft_dda(t_coord coord, void *mlx, void *win)
{
	int 	steps;
	float	x_incr;
	float	y_incr;
	float	x;
	float	y;

	coord.delta_x = coord.x2 - coord.x1;
	coord.delta_y = coord.y2 - coord.y1;

	if (ft_abs(coord.delta_x) > ft_abs(coord.delta_y))
		steps = fabs(coord.delta_x);
	else
		steps = fabs(coord.delta_y);
	
	x_incr = coord.delta_x / (float) steps;
	y_incr = coord.delta_y / (float) steps;

	x = coord.x1;
	y = coord.y1;

	while (steps)
	{
		mlx_pixel_put(mlx, win, x, y, rgb_to_int(1, 1, 1));
		x += x_incr;
		y += y_incr;
		steps--;
	}
}

int	mouse_hook(int button, int x, int y, t_program *param)
{
	t_coord 	coord;
	coord.x1 = 500;
	coord.y1 = 500;
	coord.x2 = x;
	coord.y2 = y;

	ft_dda(coord, param->mlx, param->win);

	(void)button;

	return (0);
}

int	main()
{
	t_program	ptr;
	int			win_x;
	int			win_y;

	win_x = 1000;
	win_y = 1000;

	ptr.mlx = mlx_init();
	ptr.win = mlx_new_window(ptr.mlx, win_x, win_y, "window");


	mlx_mouse_hook(ptr.win, mouse_hook, &ptr);

	mlx_loop(ptr.mlx);
}
