/*
** EPITECH PROJECT, 2022
** My_Teams
** File description:
** get_cmd_subscribe_teams
*/

#include <unistd.h>
#include "get_command.h"
#include "reply_codes.h"
#include "logging_client.h"

int subscribe_responses(char **tab, char *code_response)
{
    if (!strcmp(code_response, "13"))
        client_error_unauthorized();
    if (!strcmp(code_response, "30"))
        client_error_unknown_team(tab[1]);
    if (!strcmp(code_response, "02"))
        client_print_subscribed(tab[1], tab[3]);
    free(tab);
    return 0;
}

int subscribe_teams(char *av, int socket)
{
    char code_response[3] = {0};
    char **tab_res = NULL;

    if (check_params(av) == 1)
        tab_res = send_command(av, tab_res, "\"SUB\" ", socket);
    else {
        printf("Command is not good, use /help for more information !\n");
        return (-1);
    }
    if (tab_res == NULL) {
        printf("Tab_res == NULL\n");
        free(tab_res);
        return -1;
    }
    strncpy(code_response, tab_res[0], 2);
    return subscribe_responses(tab_res, code_response);
}
