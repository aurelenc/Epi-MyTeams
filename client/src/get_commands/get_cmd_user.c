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

int user_responses(char **tab, char *code_response)
{
    if (!strcmp(code_response, "13"))
        client_error_unauthorized();
    if (!strcmp(code_response, "00"))
        client_print_user(tab[1], tab[3], atoi(tab[5]));
    if (!strcmp(code_response, "14"))
        client_error_unknown_user(tab[1]);
    free(tab);
    return 0;
}

int user(char *av, int socket)
{
    char code_response[3] = {0};
    char **tab_res = NULL;

    if (check_params(av) == 1)
        tab_res = send_command(av, tab_res, "\"USR\" ", socket);
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
    return user_responses(tab_res, code_response);
}
