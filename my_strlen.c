/*
** EPITECH PROJECT, 2022
** Day04
** File description:
** Task03
*/

int my_strlen(char const *str)
{
    int result = 0;
    for (int i = 0; str[i] != '\0' ; i++){
        result++;
    }
    return result;
}
