/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main function
*/
#include "navy.h"

int result;

static int	help(int ac, char **av)
{
	for (int i = 0; i < ac; ++i) {
		if (my_strcmp(av[i], "-h") == 0) {
			my_printf("%s%s%s%s", U1, U2, U3, U4);
			return (1);
		}
	}
	return (SUCCESS);
}

int	main(int ac, char **av)
{
	int	**map;

	if (error(ac, av) == FAILURE)
		return (FAILURE);
	if (help(ac, av) == 1)
		return (SUCCESS);
	map = get_pos(ac, av);
	if (map == NULL) {
		my_print_err("Invalid file\n");
		return (FAILURE);
	}
	return (navy(ac, av, map));
	return (SUCCESS);
}