/*
** EPITECH PROJECT, 2017
** my_sokoban
** File description:
** map_get.c
*/

#include "prototype.h"

void map_get_line(FILE *file, map_t *map, int j)
{
	for (int i = 0; i < map->nb_case_x; i++) {
		int tmp = fscanf(file, "%c", &map->tab[i][j]);

		if (tmp != EOF && map->tab[i][j] == '\t') {
			for (int k = 0; k < 8; k++) {
				map->tab[i][j] = ' ';
				i++;
			}
			i--;
		}
		else if (tmp == EOF || map->tab[i][j] == '\n') {
			for (int k = i; k < map->nb_case_x; k++)
				map->tab[k][j] = ' ';
			fseek(file, -1, SEEK_CUR);
			break;
		}
	}
}

map_t map_get(char *name_map)
{
	map_t map;
	FILE *file = open_file(name_map, "r");

	fscanf(file, "%d %d", &map.nb_case_x, &map.nb_case_y);
	map.tab = malloc(sizeof(char *) * map.nb_case_x);
	for (int i = 0; i < map.nb_case_x; i++)
		map.tab[i] = malloc(sizeof(char) * map.nb_case_y);
	for (int j = 0; j < map.nb_case_y; j++) {
		fseek(file, 1, SEEK_CUR);
		map_get_line(file, &map, j);
	}
	fclose(file);
	return (map);
}
