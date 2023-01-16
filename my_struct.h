/*
** EPITECH PROJECT, 2022
** bs_myhunter
** File description:
** struct
*/
#include <SFML/Graphics.h>
#include <stdio.h>
#include <SFML/Audio.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include  <unistd.h>
#ifndef STRUCT_H_
    #define STRUCT_H_

typedef struct game_menu {
    sfVector2f position_button;
    sfSprite *buttonSprite;
    sfTexture *buttonTexture;
    sfSprite *menuSprite;
    sfTexture *menuTexture;
    sfSprite *pauseSprite;
    sfTexture *pauseTexture;
} game_menu_t;

typedef struct game_life {
    sfVector2f position_life;
    sfSprite *lifeSprite;
    sfTexture *lifeTexture;
    sfIntRect rect;
} game_life_t;

typedef struct game {
    sfVideoMode mode;
    sfRenderWindow *window;
    sfEvent event;
    sfVector2f position_duck;
    sfVector2f position_pipe;
    sfVector2f position_dodo;
    sfVector2f position_cursor;
    sfSprite *coffinSprite;
    sfTexture *coffinTexture;
    sfSprite *deathSprite;
    sfTexture *deathTexture;
    sfSprite *mainSprite;
    sfTexture *mainTexture;
    sfSprite *pipeSprite;
    sfTexture *pipeTexture;
    sfSprite *duckSprite;
    sfTexture *duckTexture;
    sfSprite *dodoSprite;
    sfTexture *dodoTexture;
    sfSprite *cursorsprite;
    sfTexture *cursorTexture;
    sfFont *font;
    sfText *text;
    sfText *text_score;
    sfText *count;
    sfText *best_score;
    sfText *best_score_text;
    sfVector2f textPosition;
    sfVector2f scorePosition;
    sfVector2f bestPosition;
    sfVector2f best_textPosition;
    char *b_score;
    char a;
    char b;
    int i;
    int alive;
    int life;
    int death;
    char *score;
    char c[4];
    int counter;
    sfClock *clock;
    sfTime time;
    sfTime time_dodo;
    sfClock *clock2;
    sfClock *clock_dodo;
    sfTime time_passed;
    sfTime time_death;
    sfClock *death_clock;
    float seconds;
    float seconds_dodo;
    float seconds2;
    float seconds_death;
    float diff;
    int menu_aff;
    int max_life;
    sfIntRect rect;
    sfIntRect rect_dodo;
    sfMusic *music;
    sfMusic *luigi;
    sfMusic *theme;
} game_t;

void var_value(game_t *game);
void print_text(game_t *game, game_life_t *life);
void var_changes(game_t *game, game_life_t *life, game_menu_t *menu);
void close_window(sfRenderWindow *window);
void manage_mouse_click(sfMouseButtonEvent event);
void analyse_events(game_t *game, game_life_t *life);
void move_rect(int offset, int max_value, game_t *game, game_life_t *life);
void move_rect_2(sfIntRect *rect, sfVector2f *position, int off, int max_value);
void print_window(game_t *game, game_life_t *life);
void counter(game_t *game);
void destroy(game_t *game, game_life_t *life, game_menu_t *menu);
void renderwindow_open(game_t *game, game_life_t *life, game_menu_t *menu);
void life_create(game_t *game, game_life_t *life);
void create_b_score(game_t *game);
int my_strcmp(char const *s1, char const *s2);
int my_strlen(char const *str);
void menu_p(game_t *game, game_life_t *life, game_menu_t *menu);
void menu_info(game_t *game, game_life_t *life , game_menu_t *menu);
int my_getnbr(char const *str);
void dead_player_continue(game_t *game, game_life_t *life);
void counter_life_decreased(game_t *game, game_life_t *life);
int mouse_position(int x, int y, sfRenderWindow *window, sfVector2f pos);
void other_event(game_t *game, game_life_t *life);
void destroy_o(game_t *game, game_life_t *life, game_menu_t *menu);

#endif /* !STRUCT_H_ */
