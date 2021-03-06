/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkangas <jkangas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:44:39 by jkangas           #+#    #+#             */
/*   Updated: 2022/05/02 18:26:54 by jkangas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	get_rows_cols(int fd, t_fdf *ptr)
{
	char	*line;
	int		wordcount;
	int		rows;

	if (get_next_line(fd, &line) == -1)
		error("Error reading the file");
	wordcount = ft_wordcount(line, ' ');
	if (wordcount == 0)
		error("Error reading the file");
	ptr->cols = wordcount;
	rows = 1;
	free(line);
	while (get_next_line(fd, &line))
	{
		if (wordcount != ft_wordcount(line, ' '))
			error("Error: Invalid map!");
		rows++;
		free(line);
	}
	ptr->rows = rows;
	close(fd);
}

static void	allocate_map(t_fdf *ptr)
{
	int	i;

	i = -1;
	ptr->map = (int **)malloc(sizeof(int *) * ptr->rows);
	if (!(ptr->map))
		error("Error: Error when allocating memory for the map");
	while (++i < ptr->rows)
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
	int		i;
	int		j;
	int		fd;

	i = 0;
	fd = open(map, O_RDONLY);
	if (fd < 0)
		error("error");
	while (get_next_line(fd, &line))
	{
		tmp = ft_strsplit(line, ' ');
		j = -1;
		while (tmp[++j])
			ptr->map[i][j] = ft_atoi(tmp[j]);
		ft_free_array((void **)tmp, j);
		free(line);
		i++;
	}
	close(fd);
}

void	ft_read_map(char *map, t_fdf *ptr)
{
	int	fd;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		error("Error opening the file");
	get_rows_cols(fd, ptr);
	allocate_map(ptr);
	assign_map(map, ptr);
}
