/*
** EPITECH PROJECT, 2017
** list.h
** File description:
** Header file for linked lists
*/
#ifndef LIST_H_
#define LIST_H_

#include <stdlib.h>
#include "my.h"

struct node {
	struct node	*next;
	struct node	*prev;
	void		*data;
};

void	free_list(struct node *list, void (*ptr)(void *data));
void	display_reverse(struct node *head, void (*ptr)(void *data));
void	display_list(struct node *head, void (*ptr)(void *data));
void	my_sort_list(struct node *list, int (*ptr)(void *data, void *data_2));
void	insert_end(struct node **head, void *data);
int	get_size_list(struct node *head);
struct node	*find_node(struct node *head, int (*cmp)(void *data,
	void *data_cmp), void *to_find);

#endif /* !LIST_H_ */