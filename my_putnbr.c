/*
** EPITECH PROJECT, 2022
** Lib
** File description:
** my_putnbr
*/
int my_putchar(char c);

#include <stdarg.h>

int my_putnbr(int nb)
{
    int n = 0;
    if (nb < 0) {
        nb = -nb;
        my_putchar('-');
        n++;
    }
    if (nb < 10) {
        my_putchar('0' + nb);
        return 1;
    }
    n += my_putnbr(nb / 10);
    my_putchar((nb % 10) + '0');
    return n + 1;
}

int my_putnbr_ap(va_list ap)
{
    int nb = va_arg(ap, int);
    if (nb <= 9)
        return my_putnbr(nb);
    return my_putnbr(nb) - 1;
}
