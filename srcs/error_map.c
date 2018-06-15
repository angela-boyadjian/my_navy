/*
** EPITECH PROJECT, 2018
** error_map.c
** File description:
** error handling for map
*/
#include "navy.h"

static int	check_boat_size(char **line)
{
	int	count = 0;

	for (int i = 1; line[i] && line[i + 1]; ++i) {
		if (my_strlen(line[i]) == 1)
			++i;
		if (line[i][0] != line[i + 1][0]) {
			count = get_boat_size(line[i], line[i + 1], 0);
			if (count == FAILURE || itc(count) != line[0][0])
				return (FAILURE);
		} else if (line[i][1] != line[i + 1][1]) {
			count = get_boat_size(line[i], line[i + 1], 1);
			if (count == FAILURE || itc(count) != line[0][0])
				return (FAILURE);
		}
	}
	return (SUCCESS);
}

static int	check_length(char **line)
{

	char	c = line[0][0];
	static char cmp = '2';

	if (c != '2' && c != '3' && c != '4' && c != '5')
			return (FAILURE);
	if (c != cmp)
		return (FAILURE);
	cmp += 1;
	return (SUCCESS);
}

static int	check_values(char **line)
{
	for (int i = 0; line[i]; ++i) {
		for (int j = 0; line[i][j]; ++j) {
			if ((line[i][j] < 'A' || line[i][j] > 'H')
			&& (line[i][j] < '1' || line[i][j] > '8'))
				return (FAILURE);
		}
	}
	return (SUCCESS);
}

static int	check_missing(char **line)
{
	int	i;

	for (i = 0; line[i]; ++i);
	if (i != 3)
		return (FAILURE);
	else if (my_strlen(line[2]) != 2)
		return (FAILURE);
	return (SUCCESS);
}

int	check_file(char **line)
{
	if (check_missing(line) == FAILURE || check_length(line) == FAILURE
	|| check_values(line) == FAILURE)
		return (FAILURE);
	if (check_boat_size(line) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}