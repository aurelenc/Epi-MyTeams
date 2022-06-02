/*
** EPITECH PROJECT, 2022
** My_Teams
** File description:
** get_cmd_login
*/

#include <unistd.h>
#include "get_command.h"
#include "reply_codes.h"
#include "logging_client.h"

int login_client(char *av, int socket)
{
    char buff[4096] = {0};
    char response[2] = {0};
    char **tab_response;

    if (av == NULL)
        return -1;
    if (check_params(av) == 1)
        tab_response = send_command(av, tab_response, "LOGI ", socket);
    else
        printf("Command are not good use /help for more information !\n");
    strncpy(code_response, tab_response[0], 2);
    code_response[2] = '\0';
    if (!strcmp(code_response, "00"))
        client_event_logged_in(tab_response[1], tab_response[3]);
    free(tab_response);
    return 0;
}
