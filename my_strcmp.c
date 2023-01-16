/*
** EPITECH PROJECT, 2022
** DAy06
** File description:
** Task06
*/
#include <stdio.h>
int my_strlen(char const *str);

int other(char const *s1, char const *s2, int result, int i)
{
    while (s1[i] != '\0'){
        if (s1[i] > s2[i]){
            result = 1;
            break;
        }
        if (s1[i] < s2[i]){
            result = -1;
            break;
        }
        i++;
    }
}

int my_strcmp(char const *s1, char const *s2)
{
    int result = 0;
    int i = 0;
    int n1 = my_strlen(s1);
    int n2 = my_strlen(s2);
    if (n1 > n2){
        return 1;
    }
    if (n2 > n1){
        return -1;
    }
    other(s1, s2, result, i);
    return result;
}
