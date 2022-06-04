/*
** EPITECH PROJECT, 2022
** Epi-MyTeams
** File description:
** utils
*/

#include "get_command.h"

bool arg_is_good(int ac, char **av)
{
    if (ac != 3)
        return false;
    if (atoi(av[2]) == 0)
        return false;
    return true;
}
