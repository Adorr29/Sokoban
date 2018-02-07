/*
** EPITECH PROJECT, 2017
** my_sokoban
** File description:
** my_putstr.c
*/

#include <unistd.h>
#include "prototype.h"

int my_putstr(char *str)
{
	return (write(1, &str, my_strlen(str)));
}
