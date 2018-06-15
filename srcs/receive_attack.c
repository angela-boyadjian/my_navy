/*
** EPITECH PROJECT, 2018
** receive_attack.c
** File description:
** function to handle receive attack
*/
#include "navy.h"

int	result;

bool	check_attack(int x, int y, int **map)
{
	if (map[x - 1][y - 1] != 0 && map[x - 1][y - 1] != HIT) {
		map[x - 1][y - 1] = HIT;
		return (true);
	}
	if (map[x - 1][y - 1] != HIT)
		map[x - 1][y - 1] = MISS;
	return (false);
}

static void	respond_to_attack(int **map, char *tmp, pid_t enemy_pid)
{
	int letter = result / 10;
	int num = result % 10;

	result = 0;
	if (check_attack(num, letter, map) == true) {
		send_signal(enemy_pid, 2);
		my_printf("%s: hit\n\n", tmp);
	} else {
		send_signal(enemy_pid, 1);
		my_printf("%s: missed\n\n", tmp);
	}
}

int	receive_attack(pid_t enemy_pid, int **map, int **init_map, int **enemy)
{
	char	*tmp;

	my_printf("waiting for enemy's attack...\n");
	receive_signal();
	tmp  = convert_nb(result);
	respond_to_attack(map, tmp, enemy_pid);
	if (check_map_defeat(map, init_map) == true) {
		send_signal(enemy_pid, DEFEAT);
		print_maps(map, enemy);
		my_printf("Enemy won\n");
		return (1);
	} else {
		send_signal(enemy_pid, 88);
	}
	return (SUCCESS);
}