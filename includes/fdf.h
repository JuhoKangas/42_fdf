/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkangas <jkangas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 11:13:27 by jkangas           #+#    #+#             */
/*   Updated: 2022/04/01 14:15:17 by jkangas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include <math.h>
#include <stdio.h>
#include "../libft/libft.h"

typedef struct s_coord
{
	int		x1;
	int		x2;
	int		y1;
	int		y2;
	float	delta_x;
	float	delta_y;
}			t_coord;

typedef struct s_program
{
	void	*mlx;
	void	*win;
}			t_program;

int		rgb_to_int(double r, double g, double b);
int		mouse_hook(int button, int x, int y, t_program *param);

#endif