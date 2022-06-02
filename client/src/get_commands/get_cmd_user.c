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

int user(char *av, int socket)
{
    char code_response[3];
    char **tab_response = NULL;

    if (check_params(av) == 1)
        tab_response = send_command(av, tab_response, "USR ", socket);
    else {
        printf("Command are not good use /help for more information !\n");
        return -1;
    }
    strncpy(code_response, tab_response[0], 2);
    code_response[2] = '\0';
    if (!strcmp(code_response, "14"))
        client_error_unauthorized();

    if (!strcmp(code_response, "40"))
        client_print_user(tab_response[1], tab_response[3], atoi(tab_response[5]));
    // char const *user_uuid,
    // char const *user_name,
    // int user_status);

    if (!strcmp(code_response, "33"))
        client_error_unknown_user(tab_response[1]);
    // char const *user_uuid);


    free(tab_response);
    return 0;
}
