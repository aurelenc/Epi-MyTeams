/*
** EPITECH PROJECT, 2022
** Epi-MyTeams
** File description:
** make_command_rfc_compatible
*/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool make_command_rfc_compatible(char *dest, char *command, char *av)
{
    strcat(dest, "LOGI ");
    if (dest == NULL) {
        return false;
    }
    strcat(dest, av);
    if (dest == NULL) {
        return false;
    }
    strcat(dest, "\n");
     if (dest == NULL) {
        return false;
    }
    return true;
}