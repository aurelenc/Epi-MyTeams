/*
** EPITECH PROJECT, 2022
** Epi-MyTeams
** File description:
** get_cmd_help
*/

#include <unistd.h>
#include "get_command.h"
#include "reply_codes.h"
#include "logging_client.h"

int help(char *av, int socket)
{
    if (check_params(av) == 0)
        printf("Read the Man !\n");
    else {
        printf("Command is not good, use /help for more information !\n");
        return -1;
    }
    return 0;
}
