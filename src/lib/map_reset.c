/*
** EPITECH PROJECT, 2017
** my_sokoban
** File description:
** map_reset.c
*/

#include "prototype.h"

void map_reset(map_t *map, char *map_name)
{
	map_destroy(map);
	*map = map_get(map_name);
}
