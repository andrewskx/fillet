/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboscan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 16:34:43 by anboscan          #+#    #+#             */
/*   Updated: 2017/12/07 17:41:37 by anboscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_neighbour(char arr[4][5], int i, int j, int blocks)
{
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (arr[i][j] == '#')
			{
				if ((i + 1) < 4 && arr[i + 1][j] == '#')
					blocks++;
				if ((i - 1) > -1 && arr[i - 1][j] == '#')
					blocks++;
				if ((j + 1) < 4 && arr[i][j + 1] == '#')
					blocks++;
				if ((j - 1) > -1 && arr[i][j - 1] == '#')
					blocks++;
			}
			j++;
		}
		i++;
	}
	return (blocks == 6 || blocks == 8);
}

int		ft_check_blocks(char arr[4][5], int i, int j, int dots)
{
	int blocks;

	blocks = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (arr[i][j] == '#')
				blocks++;
			if (arr[i][j] == '.')
				dots++;
			j++;
		}
		i++;
	}
	return (dots == 12 && blocks == 4 && ft_neighbour(arr, 0, 0, 0));
}

int		ft_valid_block(char arr[4][5], int i)
{
	while (i < 4)
		if (arr[i++][4] != '\n')
			return (0);
	return (1 && ft_check_blocks(arr, 0, 0, 0));
}


int		ft_valid_file(char *str, int i, int fd, t_fillit *data)
{
	char arr[4][5];
	char symbol;
	int j;
	int blocks;

	blocks = 0;
	if ((fd = open(str, O_RDONLY)) != -1)
	{
		while (1)
		{
			i = 0;
			while (i < 4)
				if (read(fd, arr[i++], 5) != 5)
					return (0);
			if (!ft_valid_block(arr, 0))
				return (0);
			blocks++;
			ft_read(arr, blocks - 1, data);
			if (read(fd, &symbol, 1))
			{
				if (symbol != '\n')
					return (0);
			}
			else 
				break ;
		}
	}
	close(fd);
	return (blocks);
}




