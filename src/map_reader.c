/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkangas <jkangas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:44:39 by jkangas           #+#    #+#             */
/*   Updated: 2022/04/13 18:15:41 by jkangas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	get_rows_cols(int fd, t_fdf *ptr)
{
	char	*line;
	int		wordcount;
	int		rows;

	get_next_line(fd, &line);
	wordcount = ft_wordcount(line, ' ');
	ptr->cols = wordcount;
	rows = 1;
	while (get_next_line(fd, &line))
		rows++;
	ptr->rows = rows;
	close(fd);
}

static void	allocate_map(t_fdf *ptr)
{
	int	i;

	i = -1;
	ptr->map = (int **)malloc(sizeof(int *) * ptr->rows);
	if (!(ptr->map))
		error("error");
	while (++i <= ptr->rows)
	{
		ptr->map[i] = (int *)malloc(sizeof(int) * ptr->cols);
		if (!(ptr->map[i]))
			ft_free_array((void **)ptr->map, i);
	}
}

static void	assign_map(char *map, t_fdf *ptr)
{
	char	**tmp;
	char	*line;
	int		n;
	int		i;
	int		fd;

	i = 0;
	fd = open(map, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		tmp = ft_strsplit(line, ' ');
		n = -1;
		while (tmp[++n])
			ptr->map[i][n] = ft_atoi(tmp[n]);
		ft_free_array((void **)tmp, n);
		i++;
	}
	close(fd);
}

void	ft_read_map(int fd, char *map, t_fdf *ptr)
{
	get_rows_cols(fd, ptr);
	allocate_map(ptr);
	assign_map(map, ptr);
	for (int i = 0; i < ptr->rows; i++)
	{
		for (int j = 0; j < ptr->cols; j++)
		{
			ft_putnbr(ptr->map[i][j]);
			ft_putchar('\t');
		}
		ft_putchar('\n');
	}
}