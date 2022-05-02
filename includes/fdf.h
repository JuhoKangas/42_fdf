/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkangas <jkangas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 11:13:27 by jkangas           #+#    #+#             */
/*   Updated: 2022/05/02 14:22:08 by jkangas          ###   ########.fr       */
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
# define SCREEN_W 1920
# define SCREEN_H 1080

/*--KEY CONTROLS--*/
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124

typedef struct s_fdf
{
	int		**map;
	int		x_off;
	int		y_off;
	int		zoom;
	void	*mlx;
	void	*win;
	int		rows;
	int		cols;
	int		view;
}			t_fdf;

typedef struct s_coord
{
	int		x1;
	int		x2;
	int		y1;
	int		y2;
	float	delta_x;
	float	delta_y;
}			t_coord;

int		key_hook(int key, t_fdf *data);
int		error(char *str);
void	ft_read_map(char *map, t_fdf *ptr);
void	ft_init_map(t_fdf *ptr);
void	ft_draw_map(t_fdf *ptr);
void	display_ui(t_fdf *data);

/*--UTILITY FUNCTIONS--*/
int		rgb_to_int(double r, double g, double b);
void	init_struct(t_fdf *data);

#endif