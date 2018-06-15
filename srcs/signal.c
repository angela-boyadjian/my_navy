/*
** EPITECH PROJECT, 2018
** signal.c
** File description:
** signal handling
*/
#include "navy.h"

void	receive_signal(void)
{
	for (int i = 0; i <= 31; ++i)
		pause();
}

void	send_signal(pid_t enemy_pid, int nb)
{
	for (int i = 31; i >= 0; --i) {
		usleep(2000);
		if (is_bit_set(nb, i) == 1)
			kill(enemy_pid, SIGUSR1);
		else
			kill(enemy_pid, SIGUSR2);
	}
}