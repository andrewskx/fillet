#ifndef	_FILLIT_H
#define _FILLIT_H
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
typedef		struct 		s_coord
{
	int x;
	int y;
}						t_coord;
typedef		struct 		s_fillit
{
	t_coord coord[4];
	char	letter;
}						t_fillit;
int		ft_size(int blocks);
int		ft_valid_file(char *str, int i, int fd, t_fillit *data);
void		ft_read(char arr[4][5], int block, t_fillit *data);
#endif
