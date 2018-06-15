/*
** EPITECH PROJECT, 2017
** convert.c
** File description:
** convert char to int
*/
#include "navy.h"

int	cti(char c)
{
	return (c - 48);
}

char	itc(int nb)
{
	return (nb + 48);
}

char	*convert_nb(int nb)
{
	char	*save = malloc(sizeof(char) * 3);

	save[0] = itc(nb / 10) + 16;
	save[1] = itc(nb % 10);
	save[2] = 0;
	return (save);
}