/*
** EPITECH PROJECT, 2017
** my_sokoban
** File description:
** my_strlen.c
*/

int my_strlen(char *str)
{
	int i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}
