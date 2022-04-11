/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkangas <jkangas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:44:39 by jkangas           #+#    #+#             */
/*   Updated: 2022/04/11 19:05:10 by jkangas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_read_map(int fd)
{
	int		map[10][10];
	char	**tmp;
	char	*line;
	int		n;
	int		i;

	i = 0;
	while (get_next_line(fd, &line))
	{
		tmp = ft_strsplit(line, ' ');
		n = -1;
		while (tmp[++n])
			map[i][n] = ft_atoi(tmp[n]);
		ft_free_array((void **)tmp, n);
		i++;
	}
	n = 0;
	while (n < 10)
	{
		ft_putnbr(map[0][n]);
		ft_putchar(' ');
		n++;
	}
	close(fd);
}