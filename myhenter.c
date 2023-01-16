/*
** EPITECH PROJECT, 2022
** bs_myhunter
** File description:
** bs_myhenter
*/

#include "my_struct.h"
int my_putnbr(int nb);

void destroy_o(game_t *game, game_life_t *life, game_menu_t *menu)
{
    sfText_destroy(game->text_score);
    sfText_destroy(game->best_score);
    sfText_destroy(game->best_score_text);
    sfSprite_destroy(life->lifeSprite);
    sfTexture_destroy(life->lifeTexture);
    sfRenderWindow_destroy(game->window);
    sfSprite_destroy(game->pipeSprite);
    sfSprite_destroy(menu->menuSprite);
    sfSprite_destroy(menu->pauseSprite);
    sfTexture_destroy(menu->menuTexture);
    sfTexture_destroy(menu->pauseTexture);
    sfSprite_destroy(game->coffinSprite);
}

void start(void)
{
    struct game game;
    struct game_life life;
    struct game_menu menu;
    game.b_score = malloc(sizeof(char) * 100);
    char *buff = malloc(sizeof(char) * 100);
    int fd = open("src/score.txt",O_RDONLY);
    for (int i = 1; i != 0; i = read(fd,buff,100));
    game.b_score = buff;
    var_value(&game);
    var_changes(&game, &life, &menu);
    renderwindow_open(&game, &life, &menu);
    write(1,"You Score is: \n", 15);
    my_putnbr(game.counter);
    destroy(&game, &life, &menu);
    if (my_strcmp(game.b_score, game.c) < 0){
        int fa = open("src/score.txt",O_WRONLY);
        write(fa, game.c, my_strlen(game.c));
    }
    free(buff);
}

int main(int argc, char **argv)
{
    if (argc > 1){
        if (argv[1][1] == 'h' && argv[1][2] == '\0'){
            write(1,"USAGE : click on the duck to kill it and get points\n"\
            , 52);
            write(1,"        if you miss 5 times, you lose\n", 38);
            write(1,"        you can click on the screen with a right click,\n"\
            , 56);
            write(1,"        you can pause the game with the ESC key\n", 48);
            write(1,"        PS: DON'T KILL LUIGI\n", 29);
            return 0;
        }
        return 84;
    } else {
        srand(time(NULL));
        start();
        return 0;
    }
}
