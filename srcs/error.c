/*
** EPITECH PROJECT, 2018
** error.c
** File description:
** error handling
*/
#include "navy.h"

int	get_boat_size(char *s1, char *s2, int nb)
{
	if (s1[nb] > s2[nb]) {
		return ((cti(s1[nb]) - cti(s2[nb])) + 1);
	} else if (s1[nb] < s2[nb]) {
		return ((cti(s2[nb]) - cti(s1[nb])) + 1);
	} else {
		return (FAILURE);
	}

}

int	error(int ac, char **av)
{
	(void)av;
	if (ac < 2) {
		my_print_err("Not enough arguments\n");
		return (FAILURE);
	}
	return (SUCCESS);
}