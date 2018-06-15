/*
** EPITECH PROJECT, 2017
** parsing.c
** File description:
** parsing map
*/
#include "navy.h"

int result;

void	modif_save(char *save)
{
	for (int i = 0; save[i]; ++i) {
		if (save[i] >= 'A' && save[i] <= 'H')
			save[i] = save[i] - 16;
	}
}

static int	fill_map(char *save, int **map, char **line)
{
	int	ship;
	int	save_one;
	int	save_bis;
	int	j;

	if (check_file(line) == FAILURE)
		return (FAILURE);
	ship = cti(save[0]);
	save_one = cti(save[6]);
	save_bis = cti(save[5]);
	if (save[2] == save[5]) {
		j = cti(save[2]) - 1;
		for (int i = cti(save[3]) - 1; i != save_one; ++i)
			map[i][j] = ship;
	} else {
		j = cti(save[3]) - 1;
		for (int i = cti(save[2]) - 1; i != save_bis; ++i)
			map[j][i] = ship;
	}
	return (SUCCESS);
}

int	**init_map(void)
{
	int	**map = malloc(sizeof(*map) * 9);

	if (map == NULL)
		return (NULL);
	for (int i = 0; i < 8; ++i) {
		map[i] = malloc(sizeof(**map) * 9);
		if (map[i] == NULL)
			return (NULL);
		for (int j = 0; j < 8; ++j)
			map[i][j] = 0;
		map[i][8] = -1;
	}
	map[8] = NULL;
	return (map);
}

static int get_map(int fd, int **map)
{
	char	*save;
	char	**line = NULL;
	int	count;

	save = get_next_line(fd);
	for (count = 0; save != NULL; ++count) {
		if (save == NULL)
			break;
		modif_save(save);
		line = my_str_to_wordtab_delim(save, ":");
		if (fill_map(save, map, line) == FAILURE)
			return (FAILURE);
		free(save);
		save = get_next_line(fd);
	}
	if (count != 4)
		return (FAILURE);
	return (count);
}

int	**get_pos(int ac, char **av)
{
	int	fd;
	int	**map = init_map();

	if (ac == 2)
		fd = open(av[1], O_RDONLY);
	else
		fd = open(av[2], O_RDONLY);
	if (fd == -1)
		return (NULL);
	if (get_map(fd, map) == FAILURE)
		return (NULL);
	return (map);
}