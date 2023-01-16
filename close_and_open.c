/*
** EPITECH PROJECT, 2022
** bs_myhunter
** File description:
** close_and_open
*/
#include "my_struct.h"

void menu_p(game_t *game, game_life_t *life, game_menu_t *menu)
{
    sfRenderWindow_clear(game->window, sfBlack);
    sfRenderWindow_drawSprite(game->window, menu->pauseSprite, NULL);
    sfRenderWindow_display(game->window);
    sfRenderWindow_setMouseCursorVisible(game->window, sfTrue);
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        sfVector2i mouse = sfMouse_getPositionRenderWindow(game->window);
        if (game->event.type == sfEvtClosed){
            sfRenderWindow_close(game->window);
        }
        if (game->event.type == sfEvtKeyPressed &&
        game->event.key.code == sfKeyEscape)
            game->menu_aff = 0;
        if (game->event.type == sfEvtMouseButtonPressed && mouse.x >= 813 &&
        mouse.x <= 1106 && mouse.y >= 320 && mouse.y <= 380)
            game->menu_aff = 0;
        if (game->event.type == sfEvtMouseButtonPressed && mouse.x >= 813 &&
        mouse.x <= 1106 && mouse.y >= 558 && mouse.y <= 630)
            sfRenderWindow_close(game->window);
    }
}

void menu_a(game_t *game, game_life_t *life, game_menu_t *menu)
{
    sfRenderWindow_clear(game->window, sfBlack);
    sfRenderWindow_drawSprite(game->window, menu->menuSprite, NULL);
    sfRenderWindow_display(game->window);
    sfRenderWindow_setMouseCursorVisible(game->window, sfTrue);
    while (sfRenderWindow_pollEvent(game->window, &game->event)){
        sfVector2i mouse = sfMouse_getPositionRenderWindow(game->window);
        if (game->event.type == sfEvtClosed){
            sfRenderWindow_close(game->window);
        }
        if (game->event.type == sfEvtKeyPressed &&
        game->event.key.code == sfKeyEscape)
            game->menu_aff = 0;
        if (game->event.type == sfEvtMouseButtonPressed && mouse.x >= 813 &&
        mouse.x <= 1106 && mouse.y >= 320 && mouse.y <= 380)
            game->menu_aff = 0;
        if (game->event.type == sfEvtMouseButtonPressed && mouse.x >= 813 &&
        mouse.x <= 1106 && mouse.y >= 558 && mouse.y <= 630){
            sfRenderWindow_close(game->window);
        }
    }
}

void destroy(game_t *game, game_life_t *life, game_menu_t *menu)
{
    sfSprite_destroy(game->duckSprite);
    sfSprite_destroy(game->dodoSprite);
    sfSprite_destroy(game->mainSprite);
    sfSprite_destroy(game->cursorsprite);
    sfTexture_destroy(game->duckTexture);
    sfTexture_destroy(game->dodoTexture);
    sfTexture_destroy(game->pipeTexture);
    sfTexture_destroy(game->mainTexture);
    sfTexture_destroy(game->cursorTexture);
    sfClock_destroy(game->clock);
    sfClock_destroy(game->clock2);
    sfText_destroy(game->text);
    sfFont_destroy(game->font);
    sfMusic_destroy(game->music);
    sfMusic_destroy(game->luigi);
    sfMusic_destroy(game->theme);
    destroy_o(game, life, menu);
}

void my_game_window(game_t *game, game_life_t *life, game_menu_t *menu)
{
    counter(game);
    game->seconds = game->time.microseconds / 1000000.0;
    if (game->seconds > 0.03){
        move_rect(108, 1919, game, life);
        sfSprite_setPosition(game->duckSprite, game->position_duck);
        sfClock_restart(game->clock);
    }
    game->seconds_dodo = game->time_dodo.microseconds / 1000000.0;
    if (game->seconds_dodo > 0.1){
        move_rect_2(&game->rect_dodo, &game->position_dodo, 54, 1919);
        sfSprite_setPosition(game->dodoSprite, game->position_dodo);
        sfClock_restart(game->clock_dodo);
    }
    game->seconds2 = game->time_passed.microseconds / 1000000.0;
    if (game->seconds2 > 10 && game->counter != 0 && game->diff > 1){
        game->diff -= 0.2;
        sfClock_restart(game->clock2);
    }
    print_window(game, life);
}

void renderwindow_open(game_t *game, game_life_t *life, game_menu_t *menu)
{
    sfMusic_play(game->theme);
    while (sfRenderWindow_isOpen(game->window)){
        if (game->menu_aff == 0){
            my_game_window(game, life, menu);
        }
        if (game->menu_aff == 1){
            menu_a(game, life, menu);
        }
        if (game->menu_aff == 2){
            menu_p(game, life, menu);
        }
    }
}
