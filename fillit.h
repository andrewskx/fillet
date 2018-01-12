/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboscan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 19:58:14 by anboscan          #+#    #+#             */
/*   Updated: 2017/12/08 20:19:56 by anboscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FILLIT_H

# define _FILLIT_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef	struct	s_coord
{
	int x;
	int y;
}				t_coord;
typedef	struct	s_fillit
{
	t_coord coord[4];
	char	letter;
}				t_fillit;
int				ft_error(int arg);
int				ft_size(int blocks);
int				ft_open(char *str, int fd, t_fillit *data);
int				ft_valid_file(int i, int fd, t_fillit *data);
void			ft_read(char arr[4][5], int block, t_fillit *data);
int				ft_check_output(char **map, int size, t_coord *x);
void			ft_print_map(char **map, int size);
int				back(t_fillit *data, char **map, int current_block, t_coord x);
#endif
