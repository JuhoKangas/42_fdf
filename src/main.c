/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkangas <jkangas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:23:07 by jkangas           #+#    #+#             */
/*   Updated: 2022/04/28 19:41:09 by jkangas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	t_fdf		ptr;

	if (argc != 2)
		error("error: usage ./fdf [MAP_FILE]");
	ptr.mlx = mlx_init();
	ptr.win = mlx_new_window(ptr.mlx, SCREEN_W, SCREEN_H, argv[1]);
	init_struct(&ptr);
	ft_read_map(argv[1], &ptr);
	mlx_key_hook(ptr.win, key_hook, &ptr);
	ft_draw_map(&ptr);
	mlx_loop(ptr.mlx);
}