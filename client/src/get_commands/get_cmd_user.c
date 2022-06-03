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
    char **tab_res = NULL;

    if (check_params(av) == 1)
        tab_res = send_command(av, tab_res, "USR ", socket);
    else {
        printf("Command are not good use /help for more information !\n");
        return -1;
    }
    strncpy(code_response, tab_res[0], 2);
    code_response[2] = '\0';
    if (!strcmp(code_response, "13"))
        client_error_unauthorized();
    if (!strcmp(code_response, "00"))
        client_print_user(tab_res[1], tab_res[3], atoi(tab_res[5]));
    if (!strcmp(code_response, "14"))
        client_error_unknown_user(tab_res[1]);
    free(tab_res);
    return 0;
}
