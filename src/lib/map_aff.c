/*
** EPITECH PROJECT, 2017
** my_sokoban
** File description:
** map_aff.c
*/

#include "prototype.h"
#include "texture_file.h"

static int SIZE = 64;

void aff(sfRenderWindow *window, sfVector2f pos, int dir, char *name_file)
{
	sfTexture *texture = sfTexture_createFromFile(name_file, NULL);
	sfSprite *sprite = sfSprite_create();
	sfVector2f scale;
	sfVector2f middle;
	sfFloatRect rect;

	sfSprite_setTexture(sprite, texture, sfTrue);
	rect = sfSprite_getLocalBounds(sprite);
	scale.x = SIZE / rect.width;
	scale.y = SIZE / rect.height;
	middle.x = rect.width / 2;
	middle.y = rect.height / 2;
	sfSprite_scale(sprite, scale);
	sfSprite_setOrigin(sprite, middle);
	sfSprite_setPosition(sprite, pos);
	sfSprite_setRotation(sprite, 90 * dir);
	sfRenderWindow_drawSprite(window, sprite, NULL);
	sfTexture_destroy(texture);
	sfSprite_destroy(sprite);
}

void map_aff_if(sfRenderWindow *window, char c, sfVector2f pos, int dr)
{
	if (c != ' ') {
		c == '#' ? aff(window, pos, 0, TEXTURE_WALL) : 0;
		c == '.' || c == 'P' ? aff(window, pos, 0, TEXTURE_GROUND) : 0;
		if (c == 'O' || c == 'x' || c == 'Q')
			aff(window, pos, 0, TEXTURE_SOCLE);
		c == 'X' || c == 'x' ? aff(window, pos, 0, TEXTURE_BOX) : 0;
		c == 'P' || c == 'Q' ? aff(window, pos, dr, TEXTURE_PLAYER) : 0;
	}
}

void map_aff(sfRenderWindow *window, map_t *map, int dir)
{
	sfVector2u win_size = sfRenderWindow_getSize(window);

	sfRenderWindow_clear(window, sfBlack);
	for (int j = 0; j < map->nb_case_y; j++) {
		for (int i = 0; i < map->nb_case_x; i++) {
			sfVector2f pos;

			pos.x = i * SIZE + SIZE / 2 + win_size.x / 2;
			pos.x -= map->nb_case_x * SIZE / 2;
			pos.y = j * SIZE + SIZE / 2 + win_size.y / 2;
			pos.y -= map->nb_case_y * SIZE / 2;
			map_aff_if(window, map->tab[i][j], pos, dir);
		}
	}
	sfRenderWindow_display(window);
}
