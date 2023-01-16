/*
** EPITECH PROJECT, 2022
** Day03
** File description:
** my_put_char
*/
int write(int, void *, int);

void my_putchar(char c)
{
    write(1, &c, 1);
}
