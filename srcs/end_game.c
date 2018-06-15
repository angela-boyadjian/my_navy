/*
** EPITECH PROJECT, 2018
** end_game.c
** File description:
** end game functions
*/
#include "navy.h"

bool	check_map_defeat(int **map, int **init_map)
{
	for (int i = 0; init_map[i]; ++i) {
		for (int j = 0; j < 8; ++j) {
			if (init_map[i][j] != 0 && map[i][j] != HIT)
				return (false);
		}
	}
	return (true);
}
