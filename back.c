/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboscan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 18:56:57 by anboscan          #+#    #+#             */
/*   Updated: 2018/01/06 18:45:56 by anboscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_set_dot(t_fillit *data, char **map, int i, int j)
{
	int k;

	k = 0;
    while (k < 4)
	{
		map[data->coord[k].x + i][data->coord[k].y + j] = '.';
		k++;
	}
}

int		ft_check_space(t_fillit *data, char **map, t_coord xy, int size)
{
	int i;
	int j;
	int k;

	i = xy.x;
	j = xy.y;
	k = 0;
	while (k < 4)
	{
		if (((data->coord[k].x + i) >= size) ||
		map[data->coord[k].x + i][data->coord[k].y + j] != '.'
		|| ((data->coord[k].y + j) >= size))
			return (0);
		k++;
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

int		back(t_fillit *data, char **map, int current_block, t_coord x)
{
	t_coord xy;

	if (current_block == x.x)
		return (1);
	xy.x = 0;
	while (xy.x < x.y)
	{
		xy.y = 0;
		while (xy.y < x.y)
		{
			if (ft_check_space(&data[current_block], map, xy, x.y))
			{
				ft_set_letter(&data[current_block], map, xy.x, xy.y);
				if (back(data, map, current_block + 1, x))
					return (1);
				else
					ft_set_dot(&data[current_block], map, xy.x, xy.y);
			}
			xy.y++;
		}
		xy.x++;
	}
	return (0);
}
