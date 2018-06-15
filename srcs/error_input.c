/*
** EPITECH PROJECT, 2018
** error_input.c
** File description:
** error handling for input
*/
#include "navy.h"

static int	check_len(char *save)
{
	if (my_strlen(save) != 2)
		return (FAILURE);
	return (SUCCESS);
}

static int	is_valid(char *save)
{
	for (int i = 0; save[i]; ++i) {
		if ((save[i] < 'A' || save[i] > 'H')
			&& (save[i] < '1' || save[i] > '8'))
				return (FAILURE);
	}
	return (SUCCESS);
}

int	check_input(char *save)
{
	if (check_len(save) == FAILURE || is_valid(save) == FAILURE) {
		my_putstr("wrong position\n");
		return (FAILURE);
	}
	return (SUCCESS);
}
