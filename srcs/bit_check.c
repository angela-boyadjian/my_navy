/*
** EPITECH PROJECT, 2017
** bit_check.c
** File description:
** check bit
*/
#include "navy.h"

int result;

bool	is_bit_set(int c, int n)
{
	return (1 & (c >> n));
}

void	send_pid(pid_t enemy_pid, pid_t my_pid)
{
	for (int i = 31; i >= 0; --i) {
		usleep(8000);
		if (is_bit_set(my_pid, i) == 1)
			kill(enemy_pid, SIGUSR1);
		else
			kill(enemy_pid, SIGUSR2);
	}
}