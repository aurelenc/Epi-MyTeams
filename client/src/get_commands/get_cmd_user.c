/*
** EPITECH PROJECT, 2022
** Epi-MyTeams
** File description:
** get_cmd_user
*/

#include <unistd.h>
#include "get_command.h"
#include "reply_codes.h"
#include "logging_client.h"

int logout_client(char *av, int socket)
{
    char code_response[3];
    char **tab_response = NULL;

    if (check_params(av) == 0)
        tab_response = send_command(av, tab_response, "LOGO ", socket);
    else {
        printf("Command are not good use /help for more information !\n");
        return -1;
    }
    strncpy(code_response, tab_response[0], 2);
    code_response[2] = '\0';
    if (!strcmp(code_response, "15"))
        client_event_logged_out(tab_response[1], tab_response[3]);
    if (!strcmp(code_response, "14"))
        client_error_unauthorized();
    free(tab_response);
    return 0;
}