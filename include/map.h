/*
** EPITECH PROJECT, 2017
** my_sokoban
** File description:
** map.h
*/

#ifndef MAP_H_
#define MAP_H_

typedef struct
{
	int nb_case_x;
	int nb_case_y;
	char **tab;
} map_t;

map_t map_get(char *name_map);
void map_destroy(map_t *map);
void map_aff(sfRenderWindow *window, map_t *map, int dir);
void map_reset(map_t *map, char *map_name);

#endif
