/*
** EPITECH PROJECT, 2018
** navy.h
** File description:
** navy header file
*/
#ifndef NAVY_H_
#define NAVY_H_
#include "my.h"
#include "get_next_line.h"
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#define	MISS 42
#define HIT 50
#define	FAILURE 84
#define	SUCCESS 0
#define DEFEAT 99
#define U1 "USAGE\n\t./navy [first_player_pid] navy_positions\n"
#define U2 "DESCRIPTION\n\tfirst_player_pid:  only for the 2nd player.  "
#define U3 "pid of the first player.\n\tnavy_positions:\tfile representing "
#define U4 "the positions pf the ships.\n"

extern int	result;

bool		check_map_defeat(int **map, int **init_map);
int		navy(int ac, char **av, int **map);
void		send_signal(pid_t enemy_pid, int nb);
void		receive_signal(void);
void		handle_sig(int sig);
int		cti(char c);
void		print_map(int **map, int nb);
int		**init_map(void);
bool		is_bit_set(int c, int n);
void		send_pid(pid_t enemy_pid, pid_t my_pid);
int		**get_pos(int ac, char **av);
void		modif_save(char *save);
bool		check_attack(int x, int y, int **map);
char		*convert_nb(int nb);
char		itc(int nb);
int		game_first(int **map, int **enemy, pid_t enemy_pid);
int		game_second(int **map, int **enemy, pid_t enemy_pid);
int		get_boat_size(char *s1, char *s2, int nb);
int		check_file(char **line);
int		error(int ac, char **av);
void		print_maps(int **map, int **enemy);
int		send_attack(pid_t enemy_pid, int **enemy,
		char *save, int **map);
int		receive_attack(pid_t enemy_pid, int **map,
		int **init_map, int **enemy);
int		check_input(char *save);

#endif /* !NAVY_H_ */