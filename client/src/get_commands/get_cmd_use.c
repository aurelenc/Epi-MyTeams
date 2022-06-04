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

int use_responses(char **tab, char *code_response)
{
    if (!strcmp(code_response, "13"))
        client_error_unauthorized();
    if (!strcmp(code_response, "00"))
        printf("It's good you move !\n");
    free(tab);
    return 0;
}

int use(char *av, int socket)
{
    char code_response[3] = {0};
    char **tab_res = NULL;

    if (check_params(av) <= 3)
        tab_res = send_command(av, tab_res, "USE ", socket);
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
    return use_responses(tab_res, code_response);
}
