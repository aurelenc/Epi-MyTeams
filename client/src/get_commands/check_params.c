/*
** EPITECH PROJECT, 2022
** My_Teams
** File description:
** check_params
*/

#include "../../include/get_command.h"

int check_params(char *av)
{
    int nb_params = 1;

    printf("av = [%s]\n", av);
    if (av == NULL)
        return 0;
    for (int i = 0; av[i] != '\0'; i++)
        if (av[i] == ' ')
            nb_params += 1;
    printf("nb_params = [%i]\n", nb_params);
    return nb_params;
}