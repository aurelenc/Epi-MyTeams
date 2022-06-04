/*
** EPITECH PROJECT, 2022
** Epi-MyTeams
** File description:
** make_command_rfc_compatible
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool make_command_rfc_compatible(char *dest, const char *command, char *av)
{
    strcat(dest, command);
    if (dest == NULL)
        return false;
    if (av != NULL)
        strcat(dest, av);
    if (dest == NULL)
        return false;
    strcat(dest, "\n");
    if (dest == NULL)
        return false;
    return true;
}
