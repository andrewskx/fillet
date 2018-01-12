/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboscan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 18:39:42 by anboscan          #+#    #+#             */
/*   Updated: 2017/12/08 20:19:23 by anboscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_error(int arg)
{
	if (arg != 2)
	{
		write(1, "Usage :\n./fillit [file]\n", 25);
		return (0);
	}
	return (1);
}

int		ft_check_output(char **map, int size, t_coord *x)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (map[i][j] != '.')
				return (0);
			j++;
		}
		i++;
	}
	x->y++;
	return (1);
}

void	ft_print_map(char **map, int size)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			write(1, &map[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
