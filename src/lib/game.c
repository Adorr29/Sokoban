/*
** EPITECH PROJECT, 2017
** my_sokoban
** File description:
** game.c
*/

#include "prototype.h"

int game(sfRenderWindow *window, char *map_name)
{
	map_t map = map_get(map_name);
	char play;
	int ret = 0;
	int dir = rand() % 4;
	int delay = 20;

	while (delay > 0 && ret == 0) {
		play = play_get(window, &dir);
		ret = play == 'E' ? 1 : 0;
		move_player(&map, play);
		play == ' ' ? map_reset(&map, map_name) : 0;
		check_end(&map) == 0 ? delay-- : 0;
		map_aff(window, &map, dir);
	}
	map_destroy(&map);
	return (ret);
}
