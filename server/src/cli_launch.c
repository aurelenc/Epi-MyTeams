/*
** EPITECH PROJECT, 2022
** Epi-MyTeams
** File description:
** cli_launch
*/

#include <stdbool.h>
#include <stdio.h>

bool has_param_error(int ac, char **av)
{
    if (ac != 2)
        return true;
    return false;
}

int display_help(void)
{
    printf("USAGE: ./myteams_server port\n");
    printf("\tport\tis the port number on which the server socket listens.");
    return 0;
}
