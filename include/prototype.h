/*
** EPITECH PROJECT, 2017
** my_sokoban
** File description:
** prototype.h
*/

#ifndef PROTOTYPE_H_
#define PROTOTYPE_H_

#include <SFML/Graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include "map.h"

int my_strlen(char *str);
int my_putstr(char *str);
FILE *open_file(char *name_file, char *mod);
char play_get(sfRenderWindow *window, int *dir);
void move_player(map_t *map, char play);
int check_end(map_t *map);
int game(sfRenderWindow *window, char *map_name);
void menu();

#endif
