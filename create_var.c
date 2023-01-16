/*
** EPITECH PROJECT, 2022
** bs_myhunter
** File description:
** t
*/
#include "my_struct.h"

void var_value(game_t *game)
{
    game->mode = (sfVideoMode){1919, 695, 30};
    game->window = sfRenderWindow_create(game->mode, "My Hunter",
    sfResize | sfClose, NULL);
    game->position_duck = (sfVector2f){0,100};
    game->position_pipe = (sfVector2f){0,550};
    game->position_dodo = (sfVector2f){0, 470};
    game->position_cursor = (sfVector2f){0, 0};
    game->mainSprite = sfSprite_create();
    game->mainTexture = sfTexture_createFromFile("src/first_forest.jpg", NULL);
    game->pipeSprite = sfSprite_create();
    game->pipeTexture = sfTexture_createFromFile("src/pipe.png", NULL);
    game->duckSprite = sfSprite_create();
    game->duckTexture = sfTexture_createFromFile("src/frame-1(2).png", NULL);
    game->dodoSprite = sfSprite_create();
    game->dodoTexture = sfTexture_createFromFile("src/luigi.png", NULL);
    create_b_score(game);
}

void print_text(game_t *game, game_life_t *life)
{
    sfText_setFont(game->text, game->font);
    sfText_setCharacterSize(game->text, 50);
    sfText_setString(game->text_score, game->score);
    sfText_setFont(game->text_score, game->font);
    sfText_setCharacterSize(game->text_score, 50);
    sfText_setPosition(game->text_score, game->scorePosition);
    sfText_setColor(game->text, sfColor_fromRGB(66, 173, 245));
    sfText_setColor(game->text_score, sfColor_fromRGB(66, 173, 245));
    life->lifeTexture = sfTexture_createFromFile("src/life2.png", NULL);
    life->lifeSprite = sfSprite_create();
    sfSprite_setTexture(life->lifeSprite, life->lifeTexture, sfFalse);
    life->position_life.x = 1400;
    life->position_life.y = 600;
    sfSprite_setPosition(life->lifeSprite, life->position_life);
    life->rect.top = 0;
    life->rect.left = 0;
    life->rect.width = 500;
    life->rect.height = 100;
    sfText_setString(game->text, game->c);
    sfText_setPosition(game->text, game->textPosition);
}

void var_changes(game_t *game, game_life_t *life, game_menu_t *menu)
{
    game->a = '0';
    game->b = '0';
    game->score = "Score: ";
    game->c[0] = '0';
    game->counter = 0;
    game->clock = sfClock_create();
    game->clock2 = sfClock_create();
    game->clock_dodo = sfClock_create();
    game->rect.top = 0;
    game->rect.left = 0;
    game->rect.width = 110;
    game->rect.height = 87;
    game->music = sfMusic_createFromFile("src/sound/balloon_pop.wav");
    game->luigi = sfMusic_createFromFile("src/sound/luigi.wav");
    game->theme = sfMusic_createFromFile("src/sound/theme2.wav");
    sfMusic_setVolume(game->theme, 35);
    sfMusic_setLoop(game->theme, sfTrue);
    life_create(game, life);
    print_text(game, life);
    menu_info(game, life, menu);
}

void close_window(sfRenderWindow *window)
{
    sfRenderWindow_close(window);
}
