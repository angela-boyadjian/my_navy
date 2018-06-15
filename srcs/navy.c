/*
** EPITECH PROJECT, 2018
** navy.c
** File description:
** navy function
*/
#include "navy.h"

int result;

void		handle_sig(int sig)
{
	static int i = 0;

	if (sig == SIGUSR1)
		result = result + 1;
	if (i < 31) {
		result = result << 1;
		++i;
	} else {
		i = 0;
	}
}

static int	player(pid_t my_pid, int **map, int **enemy)
{
	pid_t	enemy_pid;

	my_printf("my_pid: %d\nwaiting for enemy connexion...\n", my_pid);
	receive_signal();
	my_putstr("enemy connected\n\n");
	enemy_pid = result;
	send_pid(enemy_pid, my_pid);
	result = 0;
	return (game_first(map, enemy, enemy_pid));
}

int	navy(int ac, char **av, int **map)
{
	pid_t	my_pid = getpid();
	pid_t	enemy_pid;
	int	**enemy = init_map();

	result = 0;
	signal(SIGUSR1, handle_sig);
	signal(SIGUSR2, handle_sig);
	if (ac == 2) {
		return (player(my_pid, map, enemy));
	}
	if (ac == 3) {
		enemy_pid = my_getnbr(av[1]);
		my_printf("my_pid: %d\n", my_pid);
		my_putstr("successfly connected\n\n");
		send_pid(enemy_pid, my_pid);
		receive_signal();
		return (game_second(map, enemy, enemy_pid));
	}
	return (SUCCESS);
}