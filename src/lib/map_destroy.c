/*
** EPITECH PROJECT, 2017
** my_sokoban
** File description:
** map_destroy.c
*/

#include "prototype.h"

void map_destroy(map_t *map)
{
	for (int i = 0; i < map->nb_case_x; i++)
		free(map->tab[i]);
	free(map->tab);
}
