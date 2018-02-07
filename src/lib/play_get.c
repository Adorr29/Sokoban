/*
** EPITECH PROJECT, 2017
** my_sokoban
** File description:
** play_get.c
*/

#include "prototype.h"

char how_key()
{
	if (sfKeyboard_isKeyPressed(sfKeyLeft))
		return ('L');
	if (sfKeyboard_isKeyPressed(sfKeyRight))
		return ('R');
	if (sfKeyboard_isKeyPressed(sfKeyUp))
		return ('U');
	if (sfKeyboard_isKeyPressed(sfKeyDown))
		return ('D');
	if (sfKeyboard_isKeyPressed(sfKeySpace))
		return (' ');
	if (sfKeyboard_isKeyPressed(sfKeyEscape))
		return ('E');
	return (0);
}

char play_get(sfRenderWindow *window, int *dir)
{
	sfEvent event;

	while (sfRenderWindow_pollEvent(window, &event)) {
		if (event.type == sfEvtClosed) {
			sfRenderWindow_close(window);
			return ('E');
		}
		if (event.type == sfEvtKeyPressed) {
			char c = how_key();

			*dir = c == 'R' ? 0 : *dir;
			*dir = c == 'D' ? 1 : *dir;
			*dir = c == 'L' ? 2 : *dir;
			*dir = c == 'U' ? 3 : *dir;
			return (c);
		}
	}
	return (0);
}
