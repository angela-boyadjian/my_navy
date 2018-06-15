/*
** EPITECH PROJECT, 2017
** attack.c
** File description:
** attack fucntion
*/
#include "navy.h"

int result;

static void	modif_enemy_map(int **map, int x, int y, int i)
{
	if (i == 1)
		map[x - 1][y - 1] = HIT;
	else
		map[x - 1][y - 1] = MISS;
}

static void	receive_response(char *save, int **enemy, int num, int letter)
{
	if (result == 2) {
		modif_enemy_map(enemy, num, letter, 1);
		my_printf("%s: hit\n\n", save);
	} else {
		modif_enemy_map(enemy, num, letter, 0);
		my_printf("%s: missed\n\n", save);
	}
}

int	send_attack(pid_t enemy_pid, int **enemy, char *save, int **map)
{
	int	nb;
	char	*tmp = my_strdup(save);
	int	letter = 0;
	int	num = 0;

	modif_save(tmp);
	nb = my_getnbr(tmp);
	send_signal(enemy_pid, nb);
	letter = cti(tmp[0]);
	num = cti(tmp[1]);
	receive_signal();
	free(tmp);
	receive_response(save, enemy, num, letter);
	receive_signal();
	if (result == DEFEAT) {
		print_maps(map, enemy);
		my_printf("I won\n");
		return (SUCCESS);
	}
	return (FAILURE);
}