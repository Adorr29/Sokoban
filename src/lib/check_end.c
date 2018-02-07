/*
** EPITECH PROJECT, 2017
** my_sokoban
** File description:
** check_end.c
*/

#include "prototype.h"

int check_end(map_t *map)
{
	int nb = 0;

	for (int j = 0; j < map->nb_case_y; j++) {
		for (int i = 0; i < map->nb_case_x; i++) {
			if (map->tab[i][j] == 'O' || map->tab[i][j] == 'Q')
				nb++;
		}
	}
	return (nb);
}
