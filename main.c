/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboscan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 15:56:37 by anboscan          #+#    #+#             */
/*   Updated: 2017/12/07 17:45:48 by anboscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "fillit.h"
int		back(t_fillit *data, char **map, int current_block, int size_map);
void	print(t_fillit *data, int num);
int		ft_num_block(char *str)
{
	int blocks;
	int	fd;
	char symbol;

	fd = open(str,O_RDONLY);
	while (read(fd, &symbol, 1) == 1)
		blocks++;
	close(fd);
	return ((blocks + 1) / 21);
}

char **ft_map_malloc(int blocks)
{
	char **ptr;
	int i;
	
	i = 0;
	ptr = (char**)malloc(sizeof(char*) * blocks);
	while (i < blocks)
		ptr[i++] = (char*)malloc(sizeof(char) * blocks);
	return (ptr);
}

void	ft_map_set(char **map, int num)
{
	int i;
	int j;

	i = 0;
	while (i < num)
	{
		j = 0;
		while (j < num)
			map[i][j++] = '.';
		i++;
	}
}

int		main(int arg, char **argv)
{
	
	t_fillit	*data;
	char		**map;

	data = 0;
	int num;
	int aux;
	if (arg != 2)
	{
		write(1, "Usage :\n./fillit [file]\n", 25);
		return (0);
	}
	if ((num = ft_num_block(argv[1])) != 0)
		data = (t_fillit *)malloc(sizeof(t_fillit) * (num + 1));
		data[num].letter = 7;
	if ((num = ft_valid_file(argv[1], 0, 0, data)))
	{
		printf("\nblocks = %i", num);
		aux = num;
		num = ft_size(num);
		map = ft_map_malloc(num);
		ft_map_set(map, num);
		printf("\nmatrix = %i\n", num);
		print(data, aux);
//		back(data, map, 0, num);
		printf("\n\n\n");
		for (int i = 0; i < num; i++)
		{
			for (int j = 0; j < num; j++)
			{
				printf("%c", map[i][j]);
			}
			printf("\n");
		}
	}
	else
		printf("\nfail");

	return (0);
}
