/*
** EPITECH PROJECT, 2017
** game.c
** File description:
** game functions
*/
#include "navy.h"

int result;

int	**cpy_map(int **map)
{
	int	**new = malloc(sizeof(*new) * 9);

	for (int i = 0; map[i]; ++i) {
		new[i] = malloc(sizeof(**new) * 9);
		if (new[i] == NULL)
			return (NULL);
		for (int j = 0; j < 8; ++j)
			new[i][j] = map[i][j];
		new[i][8] = -1;
	}
	return (new);
}

static char	*get_input(void)
{
	char	*save;

	my_putstr("attack: ");
	save = get_next_line(0);
	if (save == NULL)
		return (NULL);
	while (check_input(save) == FAILURE) {
		my_putstr("attack: ");
		save = get_next_line(0);
	}
	return (save);
}

int	game_first(int **map, int **enemy, pid_t enemy_pid)
{
	int	**init_map = cpy_map(map);
	char	*save;

	while (1) {
		print_maps(map, enemy);
		save = get_input();
		if (save == NULL)
			return (FAILURE);
		result = 0;
		if (send_attack(enemy_pid, enemy, save, map) == SUCCESS)
			return (SUCCESS);
		free(save);
		print_maps(map, enemy);
		result = 0;
		if (receive_attack(enemy_pid, map, init_map, enemy) == 1)
			return (1);
	}
}

int	game_second(int **map, int **enemy, pid_t enemy_pid)
{
	char	*save;
	int	**init_map = cpy_map(map);

	while (1) {
		print_maps(map, enemy);
		result = 0;
		if (receive_attack(enemy_pid, map, init_map, enemy) == 1)
			return (1);
		print_maps(map, enemy);
		save = get_input();
		if (save == NULL)
			return (FAILURE);
		result = 0;
		if (send_attack(enemy_pid, enemy, save, map) == SUCCESS)
			return (SUCCESS);
		free(save);
	}
}