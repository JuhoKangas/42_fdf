/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkangas <jkangas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:23:07 by jkangas           #+#    #+#             */
/*   Updated: 2022/04/01 13:56:59 by jkangas          ###   ########.fr       */
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
	float	dx;
	float	dy;
	int 	steps;
	float	x_incr;
	float	y_incr;
	float	x;
	float	y;
	int		i;

	dx = coord.x2 - coord.x1;
	dy = coord.y2 - coord.y1;

	if (ft_abs(dx) > ft_abs(dy))
		steps = fabs(dx);
	else
		steps = fabs(dy);
	
	x_incr = dx / (float) steps;
	y_incr = dy / (float) steps;

	x = coord.x1;
	y = coord.y1;

	i = 0;
	while (i <= steps)
	{
		mlx_pixel_put(mlx, win, x, y, 0xffffff);
		x += x_incr;
		y += y_incr;
		i++;
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
