/*
** EPITECH PROJECT, 2017
** display.c
** File description:
** display functions
*/
#include "navy.h"

int result;

void	print_maps(int **map, int **enemy)
{
	print_map(map, 1);
	print_map(enemy, 0);
}

static void	print_first(int nb)
{
	if (nb == 1)
		my_putstr("my positions:\n");
	else
		my_putstr("enemy's positions:\n");
	my_putstr(" |A B C D E F G H\n");
	my_putstr("-+---------------\n");
}

static void	check_ship(int **map, int j, int i)
{
	if (map[j][i] != 0 && map[j][i] != HIT && map[j][i] != MISS) {
		my_put_nbr(map[j][i]);
		return;
	}
	if (map[j][i] == HIT) {
		my_putchar('x');
		return;
	}
	if (map[j][i] == MISS) {
		my_putchar('o');
		return;
	}
	my_putstr(".");
}

void	print_map(int **map, int nb)
{
	print_first(nb);
	for (int j = 0; j < 8; ++j) {
		my_put_nbr(j + 1);
		my_putchar('|');
		for (int i = 0; i < 8; ++i) {
			check_ship(map, j, i);
			if (i < 7)
				my_putchar(' ');
		}
		my_putchar('\n');
	}
	my_putstr("\n\n");
}
