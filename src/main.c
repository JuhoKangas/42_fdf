/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkangas <jkangas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:23:07 by jkangas           #+#    #+#             */
/*   Updated: 2022/03/29 14:46:56 by jkangas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"	

int rgb_to_int(double r, double g, double b)
{
    int color = 0;
    color |= (int)(b * 255);
    color |= (int)(g * 255) << 8;
    color |= (int)(r * 255) << 16;
    return (color);
}

int	main()
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		x;
	int		y;
	int		color;
	int		win_x;
	int		win_y;

	win_x = 1000;
	win_y = 1000;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, win_x, win_y, "window");

	x = 0;
	color = 0;
	while ( x < win_x)
	{
		y = 0;
		while (y < win_y)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, y, x, color);
			y++;
		}
		x++;
		color += 100;
	}
	mlx_loop(mlx_ptr);
}
