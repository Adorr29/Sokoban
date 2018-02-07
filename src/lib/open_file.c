/*
** EPITECH PROJECT, 2017
** my_sokoban
** File description:
** open_file.c
*/

#include "prototype.h"

FILE *open_file(char *name_file, char *mod)
{
	FILE *file;

	file = fopen(name_file, mod);
	if (file == NULL) {
		my_putstr("Error opening ");
		my_putstr(name_file);
		my_putstr(".\n");
		exit(0);
	}
	return (file);
}
