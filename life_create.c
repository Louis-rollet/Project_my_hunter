/*
** EPITECH PROJECT, 2022
** bs_myhunter
** File description:
** life_create
*/
#include "my_struct.h"

void menu_info(game_t *game, game_life_t *life , game_menu_t *menu)
{
    menu->position_button = (sfVector2f){0, 0};
    menu->menuSprite = sfSprite_create();
    menu->menuTexture = sfTexture_createFromFile("src/background.jpg", NULL);
    sfSprite_setTexture(menu->menuSprite, menu->menuTexture, sfFalse);
    menu->pauseSprite = sfSprite_create();
    menu->pauseTexture = sfTexture_createFromFile("src/background1.jpg", NULL);
    sfSprite_setTexture(menu->pauseSprite, menu->pauseTexture, sfFalse);
    game->rect_dodo.top = 0;
    game->rect_dodo.left = 0;
    game->rect_dodo.width = 54;
    game->rect_dodo.height = 93;
    game->i = 0;
    game->alive = 1;
    game->life = 5;
}

void create_b_score(game_t *game)
{
    game->cursorsprite = sfSprite_create();
    game->cursorTexture = sfTexture_createFromFile("src/cursor.png", NULL);
    game->deathSprite = sfSprite_create();
    game->deathTexture = sfTexture_createFromFile("src/1.png", NULL);
    game->coffinSprite = sfSprite_create();
    game->coffinTexture = sfTexture_createFromFile("src/coffin.png", NULL);
    game->textPosition = (sfVector2f){200, 0};
    game->scorePosition = (sfVector2f){0, 0};
    game->font = sfFont_createFromFile("src/font.otf");
    game->text = sfText_create();
    game->text_score = sfText_create();
    sfSprite_setTexture(game->mainSprite, game->mainTexture, sfFalse);
    sfSprite_setTexture(game->duckSprite, game->duckTexture, sfFalse);
    sfSprite_setTexture(game->pipeSprite, game->pipeTexture, sfFalse);
    sfSprite_setTexture(game->dodoSprite, game->dodoTexture, sfFalse);
    sfSprite_setTexture(game->cursorsprite, game->cursorTexture, sfFalse);
    sfSprite_setTexture(game->coffinSprite, game->coffinTexture, sfFalse);
    sfSprite_setTexture(game->deathSprite, game->deathTexture, sfFalse);
    game->menu_aff = 1;
}

void life_create(game_t *game, game_life_t *life)
{
    game->diff = 10;
    game->best_score = sfText_create();
    game->bestPosition.x = 1830;
    game->bestPosition.y = 0;
    game->max_life = 5;
    sfText_setPosition(game->best_score, game->bestPosition);
    sfText_setString(game->best_score, game->b_score);
    sfText_setFont(game->best_score, game->font);
    sfText_setCharacterSize(game->best_score, 50);
    sfText_setColor(game->best_score, sfColor_fromRGB(247, 146, 5));
    game->best_score_text = sfText_create();
    game->best_textPosition.x = 1500;
    game->best_textPosition.y = 0;
    sfText_setPosition(game->best_score_text, game->best_textPosition);
    sfText_setString(game->best_score_text, "best score: ");
    sfText_setFont(game->best_score_text, game->font);
    sfText_setCharacterSize(game->best_score_text, 50);
    sfText_setColor(game->best_score_text, sfColor_fromRGB(247, 146, 5));
}

void move_rect(int offset, int max_value, game_t *game, game_life_t *life)
{
    if (game->position_duck.x < max_value){
        if (game->rect.left <= offset){
            game->rect.left = game->rect.left + offset;
            game->position_duck.y += (int) (cos((double)
            game->position_duck.x / 180 * M_PI) * 10);
            game->position_duck.x += offset / game->diff;
        } else {
            game->rect.left = 0;
            game->position_duck.y += (int) (cos((double)
            game->position_duck.x / 180 * M_PI) * 10);
            game->position_duck.x += offset / game->diff;
        }
    } else {
        game->position_duck.x = -150;
        game->life -= 1;
        life->rect.width = game->life * 100;
        game->position_duck.y = rand() % 400;
    }
}

void move_rect_2(sfIntRect *rect, sfVector2f *position, int off, int max_value)
{
    if (position->x < max_value){
        if (rect->left <= off){
            rect->left = rect->left + off;
            position->x += off / 3;
        } else {
            rect->left = 0;
            position->x += off / 3;
        }
    } else {
        position->x = (rand() % 3000) * (-1);
    }
}
