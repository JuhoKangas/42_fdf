/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkangas <jkangas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 18:50:57 by jkangas           #+#    #+#             */
/*   Updated: 2022/04/11 18:54:47 by jkangas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_free_array(void **arr, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		ft_free(arr[i], ft_strlen(arr[i]));
		i++;
	}
	free(arr);
	arr = NULL;
	return (NULL);
}