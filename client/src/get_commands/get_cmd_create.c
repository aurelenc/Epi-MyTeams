/*
** EPITECH PROJECT, 2022
** Epi-MyTeams
** File description:
** get_cmd_create
*/

#include <unistd.h>
#include "get_command.h"
#include "reply_codes.h"
#include "logging_client.h"

int create_responses(char **t, char *code_response)
{
    if (!strcmp(code_response, "13"))
        client_error_unauthorized();
    if (!strcmp(code_response, "30"))
        client_error_unknown_team(t[1]);
    if (!strcmp(code_response, "31"))
        client_error_unknown_channel(t[1]);
    if (!strcmp(code_response, "24"))
        client_error_already_exist();
    if (!strcmp(code_response, "50"))
        client_print_team_created(t[1], t[3], t[5]);
    if (!strcmp(code_response, "51"))
        client_print_channel_created(t[1], t[3], t[5]);
    if (!strcmp(code_response, "52"))
        client_print_thread_created(t[1], t[3], atol(t[5]), t[7], t[8]);
    if (!strcmp(code_response, "53"))
        client_print_reply_created(t[1], t[3], atol(t[5]), t[7]);
    free(t);
    return 0;
}

int create(char *av, int socket)
{
    char code_response[3] = {0};
    char **tab_res = NULL;

    if (check_params(av) == 2)
        tab_res = send_command(av, tab_res, "\"CREA\" ", socket);
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
    return create_responses(tab_res, code_response);
}
