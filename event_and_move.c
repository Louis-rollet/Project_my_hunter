/*
** EPITECH PROJECT, 2022
** bs_myhunter
** File description:
** event_and_move
*/
#include "my_struct.h"

void analyse_events(game_t *game, game_life_t *life)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)){
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        if (game->event.type == sfEvtKeyPressed &&
        game->event.key.code == sfKeyEscape)
            game->menu_aff = 2;
        if (game->event.type == sfEvtMouseButtonPressed &&
        mouse_position(109, 87, game->window, game->position_duck)){
            game->position_duck.x = -150;
            game->position_duck.y = rand() % 400;
            game->counter++;
            game->life = game->max_life;
            life->rect.width = game->life * 100;
            game->music = sfMusic_createFromFile("src/sound/balloon_pop.wav");
            sfMusic_play(game->music);
            break;
        }
        other_event(game, life);
    }
}

void print_winwow_plus(game_t *game, game_life_t *life)
{
    sfRenderWindow_drawText(game->window, game->text, NULL);
    sfRenderWindow_drawText(game->window, game->text_score, NULL);
    sfRenderWindow_drawText(game->window, game->best_score, NULL);
    sfRenderWindow_drawText(game->window, game->best_score_text, NULL);
    sfRenderWindow_drawSprite(game->window, game->cursorsprite, NULL);
    sfRenderWindow_display(game->window);
    game->time = sfClock_getElapsedTime(game->clock);
    game->time_passed = sfClock_getElapsedTime(game->clock2);
    game->time_dodo = sfClock_getElapsedTime(game->clock_dodo);
}

void print_window(game_t *game, game_life_t *life)
{
    sfRenderWindow_setMouseCursorVisible(game->window, sfFalse);
    analyse_events(game, life);
    sfSprite_setPosition(game->cursorsprite, game->position_cursor);
    sfSprite_setPosition(game->pipeSprite, game->position_pipe);
    sfSprite_setTextureRect(life->lifeSprite, life->rect);
    sfRenderWindow_clear(game->window, sfBlack);
    sfRenderWindow_drawSprite(game->window, game->mainSprite, NULL);
    sfSprite_setTextureRect(game->duckSprite, game->rect);
    sfSprite_setPosition(game->duckSprite, game->position_duck);
    sfSprite_setTextureRect(game->dodoSprite, game->rect_dodo);
    if (game->alive == 1){
        sfSprite_setPosition(game->dodoSprite, game->position_dodo);
        sfRenderWindow_drawSprite(game->window, game->dodoSprite, NULL);
    }
    if (game->alive == 0)
        sfRenderWindow_drawSprite(game->window, game->coffinSprite, NULL);
    sfRenderWindow_drawSprite(game->window, game->duckSprite, NULL);
    sfRenderWindow_drawSprite(game->window, game->pipeSprite, NULL);
    sfRenderWindow_drawSprite(game->window, life->lifeSprite, NULL);
    print_winwow_plus(game, life);
}

void counter(game_t *game)
{
    int d = 0;
    game->a = game->counter % 10 + '0';
    game->c[0] = game->a;
    if (game->counter >= 10){
        game->b = game->counter / 10 % 10 + '0';
        game->c[0] = game->b;
        game->c[1] = game->a;
    }
    if (game->counter >= 100){
        d = (game->counter / 100) % 10 + '0';
        game->c[0] = d;
        game->c[1] = game->b;
        game->c[2] = game->a;
    }
    if (game->counter == 100 && game->i == 0){
        game->textPosition.x += 10;
        sfText_setPosition(game->text, game->textPosition);
        game->i++;
    }
    sfText_setString(game->text, game->c);
}
