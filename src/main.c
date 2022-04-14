/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkangas <jkangas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:23:07 by jkangas           #+#    #+#             */
/*   Updated: 2022/04/14 16:59:22 by jkangas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"	
#include "../includes/fdf.h"

int	rgb_to_int(double r, double g, double b)
{
	int	color;

	color = 0;
	color |= (int)(b * 255);
	color |= (int)(g * 255) << 8;
	color |= (int)(r * 255) << 16;
	return (color);
}

void	ft_dda(t_fdf *fdf, void *mlx, void *win)
{
	int		steps;
	float	x_incr;
	float	y_incr;
	float	x;
	float	y;

	fdf->delta_x = fdf->x2 - fdf->x1;
	fdf->delta_y = fdf->y2 - fdf->y1;
	if (ft_abs(fdf->delta_x) > ft_abs(fdf->delta_y))
		steps = fabs(fdf->delta_x);
	else
		steps = fabs(fdf->delta_y);
	x_incr = fdf->delta_x / (float) steps;
	y_incr = fdf->delta_y / (float) steps;
	x = fdf->x1;
	y = fdf->y1;
	while (steps)
	{
		mlx_pixel_put(mlx, win, x, y, rgb_to_int(1, 1, 1));
		x += x_incr;
		y += y_incr;
		steps--;
	}
}

int	mouse_hook(int button, int x, int y, t_fdf *param)
{
	param->x1 = 500;
	param->y1 = 500;
	param->x2 = x;
	param->y2 = y;
	ft_dda(param, param->mlx, param->win);
	(void)button;
	return (0);
}

int	main(int argc, char **argv)
{
	t_fdf		ptr;
	int			win_x;
	int			win_y;
	int			fd;

	win_x = 1000;
	win_y = 1000;
	if (argc != 2)
		error("error: usage ./fdf [MAP_FILE]");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error("error");
	ft_read_map(fd, argv[1], &ptr);
	ptr.mlx = mlx_init();
	ptr.win = mlx_new_window(ptr.mlx, win_x, win_y, "window");
	mlx_mouse_hook(ptr.win, mouse_hook, &ptr);
	mlx_loop(ptr.mlx);
}
