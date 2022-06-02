/*
** EPITECH PROJECT, 2022
** My_Teams
** File description:
** get_cmd_unsubscribe_teams
*/

#include <unistd.h>
#include "get_command.h"
#include "reply_codes.h"
#include "logging_client.h"

int unsubscribe_teams(char *av, int socket)
{
    char code_response[3];
    char **tab_response = NULL;

    if (av == NULL)
        return -1;
    if (check_params(av) == 1)
        tab_response = send_command(av, tab_response, "USUB ", socket);
    else
        printf("Command are not good use /help for more information !\n");
    strncpy(code_response, tab_response[0], 2);
    code_response[2] = '\0';
    if (!strcmp(code_response, "14"))
        client_error_unauthorized();

    if (!strcmp(code_response, "03"))
        client_print_unsubscribed(tab_response[1], tab_response[3]);

    if (!strcmp(code_response, "30"))
        client_error_unknown_team(tab_response[1]);


    free(tab_response);
    return 0;
}
