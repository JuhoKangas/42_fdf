/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkangas <jkangas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 11:13:27 by jkangas           #+#    #+#             */
/*   Updated: 2022/04/15 12:11:34 by jkangas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "mlx.h"

/*--SCREEN SIZE--*/
# define SCREEN_W 1000
# define SCREEN_H 1000

/*--GRID SIZE--*/
# define GRID 50
# define OFFSET 200

typedef struct s_fdf
{
	int		**map;
	int		x1;
	int		x2;
	int		y1;
	int		y2;
	float	delta_x;
	float	delta_y;
	void	*mlx;
	void	*win;
	int		rows;
	int		cols;
}			t_fdf;

int		rgb_to_int(double r, double g, double b);
int		mouse_hook(int button, int x, int y, t_fdf *param);
int		error(char *str);
void	ft_read_map(char *map, t_fdf *ptr);
void	ft_init_map(t_fdf *ptr);
void	ft_draw_map(t_fdf *ptr);

#endif