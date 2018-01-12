/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboscan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 17:06:55 by anboscan          #+#    #+#             */
/*   Updated: 2017/12/07 17:44:27 by anboscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_translation_i(char arr[4][5], int i, int j)
{
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (arr[i][j] == '#')
				return (i);
			j++;
		}
		i++;
	}
	return (0);
}

int		ft_translation_j(char arr[4][5], int i, int j)
{
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (arr[j][i] == '#')
				return (i);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_read(char arr[4][5], int block, t_fillit *data)
{
	int min_i;
	int min_j;
	int i;
	int j;
	int x;

	i = 0;
	x = 0;
	min_i = ft_translation_i(arr, 0, 0);
	min_j = ft_translation_j(arr, 0, 0);
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (arr[i][j] == '#')
			{
				data[block].coord[x].x = i - min_i;
				data[block].coord[x++].y = j - min_j;
				data[block].letter = 'A' + block;
			}
			j++;
		}
		i++;
	}
}

int		ft_size(int blocks)
{
	int i;

	i = 0;
	blocks *= 4;
	while (i * i < blocks)
		i++;
	return (i);
}

void	print(t_fillit *data, int num)
{
	int s;
	for (int k = 0; k < num; k++)
	{
		s = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (i == data[k].coord[s].x  && j == data[k].coord[s].y)
			{
				printf("%c", data[k].letter);
				s++;
			}
			else
				printf(".");
		}
		printf("\n");
	}
printf("\n");
	}
}
