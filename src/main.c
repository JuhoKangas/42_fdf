/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkangas <jkangas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:23:07 by jkangas           #+#    #+#             */
/*   Updated: 2022/04/14 19:08:41 by jkangas          ###   ########.fr       */
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

// int	mouse_hook(int button, int x, int y, t_fdf *param)
// {
// 	param->x1 = 500;
// 	param->y1 = 500;
// 	param->x2 = x;
// 	param->y2 = y;
// 	ft_dda(param, param->mlx, param->win);
// 	(void)button;
// 	return (0);
// }

int	main(int argc, char **argv)
{
	t_fdf		ptr;

	if (argc != 2)
		error("error: usage ./fdf [MAP_FILE]");
	ptr.mlx = mlx_init();
	ptr.win = mlx_new_window(ptr.mlx, SCREEN_W, SCREEN_H, "window");
	ft_read_map(argv[1], &ptr);
	// mlx_mouse_hook(ptr.win, mouse_hook, &ptr);
	ft_draw_map(&ptr);
	mlx_loop(ptr.mlx);

}
