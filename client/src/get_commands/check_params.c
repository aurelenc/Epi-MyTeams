/*
** EPITECH PROJECT, 2022
** My_Teams
** File description:
** check_params
*/

#include "get_command.h"

int check_params(char *av)
{
    int count = 0;
    int nb_params = 0;

    if (av == NULL)
        return 0;
    for (int i = 0; av[i] != '\0'; i++) {
        if (av[i] == '"' && av[i - 1] != '\\')
            count++;
        if (count % 2 == 0 && count != 0) {
            count = 0;
            nb_params++;
        }
    }
    av = manage_params(av);
    return nb_params;
}
