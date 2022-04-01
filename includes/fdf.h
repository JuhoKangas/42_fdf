/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkangas <jkangas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 11:13:27 by jkangas           #+#    #+#             */
/*   Updated: 2022/04/01 11:30:52 by jkangas          ###   ########.fr       */
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
}			t_coord;

typedef struct s_program
{
	void	*mlx;
	void	*win;
}			t_program;

int	rgb_to_int(double r, double g, double b);

#endif