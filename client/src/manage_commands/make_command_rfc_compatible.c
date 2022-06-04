/*
** EPITECH PROJECT, 2022
** Epi-MyTeams
** File description:
** make_command_rfc_compatible
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

char *add_space(char *av)
{
    char *temp = calloc(sizeof(char), (strlen(av) + 1));
    int count = 0;
    int i = 0;

    for (; av[i] != '\0'; i++) {
        if (av[i] == '\"')
            count++;
        if (count == 2 || count == 4) {
            temp = strncat(temp, av, (i + 1));
            temp = strcat(temp, " ");
            temp = strncat(temp, (av + i + 1), (strlen(av) - (i + 1)));
            break;
        }
    }
    if (i == strlen(av))
        return (av);
    return temp;
}

bool make_command_rfc_compatible(char *dest, const char *command, char *av)
{
    strcat(dest, command);
    if (dest == NULL)
        return false;
    if (av != NULL) {
        av = strdup(add_space(av));
        strcat(dest, av);
    }
    if (dest == NULL)
        return false;
    strcat(dest, "\n");
    if (dest == NULL)
        return false;
    return true;
}
