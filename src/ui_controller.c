/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_controller.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkangas <jkangas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:14:51 by jkangas           #+#    #+#             */
/*   Updated: 2022/05/02 20:06:26 by jkangas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	display_ui(t_fdf *data)
{
	char	*str1;
	char	*str2;
	char	*str3;
	char	*str4;
	char	*str5;

	str1 = "Press +/- to zoom, [ and ] to change the elevation";
	str2 = "Use arrow keys to move fdf around";
	str3 = "Use space to change the projection";
	str4 = "Use 'C' to change color";
	str5 = "Press esc to exit";
	mlx_string_put(data->mlx, data->win, 20, 50, rgb_to_int(1, 1, 1), str1);
	mlx_string_put(data->mlx, data->win, 20, 70, rgb_to_int(1, 1, 1), str2);
	mlx_string_put(data->mlx, data->win, 20, 90, rgb_to_int(1, 1, 1), str3);
	mlx_string_put(data->mlx, data->win, 20, 110, rgb_to_int(1, 1, 1), str4);
	mlx_string_put(data->mlx, data->win, 20, 130, rgb_to_int(1, 1, 1), str5);
}
