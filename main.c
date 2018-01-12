/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboscan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 15:56:37 by anboscan          #+#    #+#             */
/*   Updated: 2017/12/08 20:19:32 by anboscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_free(char **map, t_fillit *data, t_coord x)
{
	int i;

	i = 0;
	while (i < x.y)
	{
		if (map[i])
			free(map[i]);
		i++;
	}
	if (map)
		free(map);
	if (data)
		free(data);
}

int		ft_num_block(char *str)
{
	int		blocks;
	int		fd;
	char	symbol;

	blocks = 0;
	fd = open(str, O_RDONLY);
	while (read(fd, &symbol, 1) == 1)
		blocks++;
	close(fd);
	blocks = (blocks + 1) / 21;
	return (blocks);
}

char	**ft_map_malloc(int blocks)
{
	char	**ptr;
	int		i;

	i = 0;
	ptr = (char**)malloc(sizeof(char*) * (blocks + 1));
	while (i < blocks + 1)
		ptr[i++] = (char*)malloc(sizeof(char) * (blocks + 1));
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
	t_coord		x;

	map = 0;
	data = 0;
	if (!ft_error(arg))
		return (0);
	if ((x.x = ft_num_block(argv[1])) != 0)
		data = (t_fillit *)malloc(sizeof(t_fillit) * x.x);
	if ((x.x = ft_open(argv[1], 0, data)))
	{
		x.y = ft_size(x.x);
		map = ft_map_malloc(x.y);
		ft_map_set(map, x.y + 1);
		back(data, map, 0, x);
		if (ft_check_output(map, x.y, &x))
			back(data, map, 0, x);
	}
	else
		write(1, "error\n", 6);
	ft_print_map(map, x.y);
	ft_free(map, data, x);
	return (0);
}
