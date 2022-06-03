/*
** EPITECH PROJECT, 2022
** Epi-MyTeams
** File description:
** get_cmd_use
*/

#include <unistd.h>
#include "get_command.h"
#include "reply_codes.h"
#include "logging_client.h"

int use(char *av, int socket)
{
    char code_response[3];
    char **tab_response = NULL;


    if (check_params(av) <= 3)
        tab_response = send_command(av, tab_response, "USE ", socket);
    else {
        printf("Command are not good use /help for more information !\n");
        return (-1);
    }
    strncpy(code_response, tab_response[0], 2);
    code_response[2] = '\0';

    if (!strcmp(code_response, "13"))
        client_error_unauthorized();
    free(tab_response);
    return 0;
}
