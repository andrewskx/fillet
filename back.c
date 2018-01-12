/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboscan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 18:56:57 by anboscan          #+#    #+#             */
/*   Updated: 2017/12/07 16:16:49 by anboscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void	ft_set_dot(t_fillit *data, char **map)
{
	int k;

	k = 0;
	while (k < 4)
	{
		map[data->coord[k].x][data->coord[k].y] = '.';
		k++;
	}
}

int		ft_check_space(t_fillit *data, char **map, int i, int j)
{
	int size;
	int k;

	k = 0;
	size = sizeof(map[0]) / sizeof(char) - 1;
	while (k < 4)
	{
		if (((data->coord[k].x + i) > size) &&  map[data->coord[k].x + i][data->coord[k].y + j] != '.' && ((data->coord[k].y + j) > size))
			return (0);
	}
	return (1);
}

void	ft_set_letter(t_fillit *data, char **map, int i, int j)
{
	int k;

	k = 0;
	while (k < 4)
	{
		map[data->coord[k].x + i][data->coord[k].y + j] = data->letter;
		k++;
	}
}

void	print_matrix(char **map, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
}

int		back(t_fillit  *data, char **map, int current_block, int size_map)
{
	int i;
	int j;

	printf("here");
	if (data[current_block].letter == 7)
		return (1);
	i = 0;
	while (i < size_map)
	{
		j = 0;
		while (j < size_map)
		{
			if (ft_check_space(&data[current_block], map, i, j))
			{
				print_matrix(map, size_map);
				ft_set_letter(&data[current_block], map, i, j);
				if (back(data, map, current_block + 1, size_map))
					return (1);
				else
					ft_set_dot(&data[current_block], map);
			}
			j++;
		}
		i++;
	}
	return (0);
}
