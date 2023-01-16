/*
** EPITECH PROJECT, 2022
** Day04
** File description:
** Task05
*/
int verif3(char const nb)
{
    if (nb == '0' || nb == '1' || nb == '2' || nb == '3' || nb == '4'){
        return 1;
    }
    if (nb == '5' || nb == '6' || nb == '7' || nb == '8' || nb == '9'){
        return 1;
            }
    return 0;
}

int verif1(int i, int result, char const *str)
{
    while (verif3 (str[i])){
        if ((result + 2147483648) - (result * 10 - (str[i] - '0')) <= 0){
            return 0;
        }
        if ((result + 2147483648) - (result * 10 - (str[i] - '0')) == 0){
            return result;
        }
        result = result * 10 - (str[i] - '0');
        i++;
    }
    return result;
}

int verif2(int i, int result, char const *str)
{
    while (verif3 (str[i])){
        if (((result - 2147483647) + (result * 10 + (str[i] - '0'))) > result ){
            return 0;
        }
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return result;
}

int verif_negatif(int i, int is_negatif, int result ,char const *str)
{
    if (result == 1){
        if (str[i] == '-' || str[i] == '+'){
            return 1;
        }
        return 0;
    }
    if ((str[i - 1]) != '-' && str[i - 1] != '+'){
        is_negatif = 1;
    }
    if (is_negatif == (-1)){
        return verif1(i, result, str);
    }else {
        return verif2(i, result, str);
    }

}

int my_getnbr(char const *str)
{
    int i = 0;
    int result = 1;
    int is_negatif = 1;
    int fin = 0;
    while (str[i] != '\0' && !(verif3(str[i]))){
        if (str[i] == '-'){
            is_negatif = is_negatif * (-1);
        }
        if (!(verif3(str[i])) && !(verif_negatif(i, is_negatif, result ,str))){
            is_negatif = 1;
        }
        i++;
    }
    result = 0;;
    return verif_negatif(i, is_negatif, result ,str);
}
