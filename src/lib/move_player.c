/*
** EPITECH PROJECT, 2017
** my_sokoban
** File description:
** move_player.c
*/

#include "prototype.h"

void move_player_x_y(int *x, int *y, char play)
{
	*y -= play == 'U' ? 1 : 0;
	*y += play == 'D' ? 1 : 0;
	*x -= play == 'L' ? 1 : 0;
	*x += play == 'R' ? 1 : 0;
}

void move_player_p_P(map_t *map)
{
	for (int j = 0; j < map->nb_case_y; j++) {
		for (int i = 0; i < map->nb_case_x; i++) {
			if (map->tab[i][j] == 'p')
				map->tab[i][j] = 'P';
			if (map->tab[i][j] == 'q')
				map->tab[i][j] = 'Q';
		}
	}
}

void move_player_if2(map_t *map, int i, int j, char play)
{
	int tmp = 0;
	char c;
	int x = 0;
	int y = 0;

	move_player_x_y(&x, &y, play);
	if (map->tab[i + x][j + y] == 'X' || map->tab[i + x][j + y] == 'x') {
		if (map->tab[i + x * 2][j + y * 2] == '.')
			tmp = 1;
		if (map->tab[i + x * 2][j + y * 2] == 'O')
			tmp = 1;
		if (tmp) {
			c = map->tab[i + x * 2][j + y * 2] == '.' ? 'X' : 'x';
			map->tab[i + x * 2][j + y * 2] = c;
			c = map->tab[i + x][j + y] == 'X' ? 'p' : 'q';
			map->tab[i + x][j + y] = c;
			map->tab[i][j] = map->tab[i][j] == 'P' ? '.' : 'O';
		}
	}
}

void move_player_if(map_t *map, int i, int j, char play)
{
	int x = 0;
	int y = 0;

	move_player_x_y(&x, &y, play);
	if (map->tab[i][j] == 'P' || map->tab[i][j] == 'Q') {
		if (map->tab[i + x][j + y] == '.') {
			map->tab[i + x][j + y] = 'p';
			map->tab[i][j] = map->tab[i][j] == 'P' ? '.' : 'O';
		}
		if (map->tab[i + x][j + y] == 'O') {
			map->tab[i + x][j + y] = 'q';
			map->tab[i][j] = map->tab[i][j] == 'P' ? '.' : 'O';
		}
		move_player_if2(map, i, j, play);
	}
}

void move_player(map_t *map, char play)
{
	for (int j = 0; j < map->nb_case_y; j++) {
		for (int i = 0; i < map->nb_case_x; i++)
			move_player_if(map, i, j, play);
	}
	move_player_p_P(map);
}
