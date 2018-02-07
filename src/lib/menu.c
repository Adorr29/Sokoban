/*
** EPITECH PROJECT, 2017
** my_sokoban
** File description:
** menu.c
*/

#include "prototype.h"

void menu_end(sfRenderWindow *window)
{
	sfEvent event;

	while (sfRenderWindow_pollEvent(window, &event)) {
		if (event.type == sfEvtClosed) {
			sfRenderWindow_close(window);
		}
	}
}

void menu()
{
	sfVideoMode mode = {1920, 1080, 32};
	sfRenderWindow *window;
	char *str = malloc(30);

	int i = 1;
	window = sfRenderWindow_create(mode, "Sokoban", sfFullscreen, NULL);
	sfRenderWindow_setFramerateLimit(window, 30);
	sfRenderWindow_setMouseCursorVisible(window, sfFalse);
	while (sfRenderWindow_isOpen(window)) {
		menu_end(window);
		sprintf(str, "maps/normal/level%d\0", i);
		i >= 32 ? i = 1 : i++;
		sfRenderWindow_clear(window, sfBlack);
		game(window, str);
		sfRenderWindow_display(window);
	}
	sfRenderWindow_destroy(window);
}
