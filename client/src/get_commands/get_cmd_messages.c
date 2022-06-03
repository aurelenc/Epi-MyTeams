/*
** EPITECH PROJECT, 2022
** Epi-MyTeams
** File description:
** get_cmd_message
*/

#include <unistd.h>
#include "get_command.h"
#include "reply_codes.h"
#include "logging_client.h"

int message_responses(char **tab, char *code_response)
{
    if (!strcmp(code_response, "13"))
        client_error_unauthorized();

    if (!strcmp(code_response, "??"))
        for (int i = 0; tab[i + 6]; i = i + 6)
            client_private_message_print_messages(tab[i + 1], atol(tab[i + 3]), tab[i + 5]);
    if (!strcmp(code_response, "??"))
        client_error_unknown_user(tab[0]);
    free(tab);
    return 0;
}

int messages(char *av, int socket)
{
    char code_response[3] = {0};
    char **tab_res = NULL;

    if (check_params(av) == 1)
        tab_res = send_command(av, tab_res, "MSG ", socket);
    else {
        printf("Command is not good, use /help for more information !\n");
        return -1;
    }
    if (tab_res == NULL) {
        printf("Tab_res == NULL\n");
        free(tab_res);
        return -1;
    }
    strncpy(code_response, tab_res[0], 2);
    return message_responses(tab_res, code_response);
}
