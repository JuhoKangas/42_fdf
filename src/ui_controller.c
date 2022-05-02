/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_controller.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkangas <jkangas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:14:51 by jkangas           #+#    #+#             */
/*   Updated: 2022/05/02 14:31:50 by jkangas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	display_ui(t_fdf *data)
{
	char	*str1;
	char	*str2;
	char	*str3;

	str1 = "Press +/- to zoom";
	str2 = "Use arrow keys to move fdf around";
	str3 = "Press esc to exit";
	mlx_string_put(data->mlx, data->win, 20, 100, rgb_to_int(1, 1, 1), str1);
	mlx_string_put(data->mlx, data->win, 20, 115, rgb_to_int(1, 1, 1), str2);
	mlx_string_put(data->mlx, data->win, 20, 130, rgb_to_int(1, 1, 1), str3);
}