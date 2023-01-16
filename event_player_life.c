/*
** EPITECH PROJECT, 2022
** bs_myhunter
** File description:
** event_player_life
*/
#include "my_struct.h"
int my_putnbr(int nb);

void reset(game_t *game, game_life_t *life)
{
    game->menu_aff = 1;
    game->life = 5;
    game->max_life = 5;
    life->rect.width = game->life * 100;
    game->position_duck.x = -200;
    game->position_duck.y = 70;
    write(1,"You Score is: \n", 15);
    my_putnbr(game->counter);
}

void dead_player_continue(game_t *game, game_life_t *life)
{
    if (game->life == 0){
        reset(game, life);
        if (game->counter > my_getnbr(game->b_score)){
            sfText_setString(game->best_score, game->c);
            int fa = open("src/score.txt",O_WRONLY);
            write(fa, game->c, my_strlen(game->c));
            close(fa);
        }
        sfText_setString(game->text, game->c);
        game->c[0] = '0';
        game->c[1] = '\0';
        game->counter = 0;
        game->position_dodo.x = -150;
        game->alive = 1;
    }
}

void counter_life_decreased(game_t *game, game_life_t *life)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->window);
    if (game->event.type == sfEvtMouseMoved){
        game->position_cursor.x = mouse.x - 35;
        game->position_cursor.y = mouse.y - 35;
        game->position_pipe.x = mouse.x - 50;
    }
    if (game->event.type = sfEvtMouseEntered)
        sfRenderWindow_setMouseCursorVisible(game->window, sfFalse);
    if (game->counter == 10)
        game->max_life = 4;
    if (game->counter == 20)
        game->max_life = 3;
    if (game->counter == 30)
        game->max_life = 2;
    if (game->counter == 50)
        game->max_life = 1;
    dead_player_continue(game, life);
}

int mouse_position(int x, int y, sfRenderWindow *window, sfVector2f pos)
{
    if ((sfMouse_getPositionRenderWindow(window).x >= pos.x &&
        sfMouse_getPositionRenderWindow(window).x <= pos.x + x &&
        sfMouse_getPositionRenderWindow(window).y >= pos.y &&
        sfMouse_getPositionRenderWindow(window).y <= pos.y + y))
        return 1;
    return 0;
}

void other_event(game_t *game, game_life_t *life)
{
    if (game->event.type == sfEvtMouseButtonPressed &&
    mouse_position(54, 93, game->window, game->position_dodo) &&
    game->alive == 1){
        game->luigi = sfMusic_createFromFile("src/sound/luigi.wav");
        sfMusic_play(game->luigi);
        game->alive = 0;
        sfSprite_setPosition(game->coffinSprite, game->position_dodo);
        write(1,"Why did you kill Luigi ?\n", 25);
    }
    if (game->event.type == sfEvtMouseButtonPressed &&
    !(mouse_position(46, 100, game->window, game->position_duck))){
        game->life -= 1;
        game->music = sfMusic_createFromFile("src/sound/balloon_pop.wav");
        sfMusic_play(game->music);
        if (life->rect.width > 0){
            life->rect.width -= 100;
        }
    }
    counter_life_decreased(game, life);
}
