/*
** EPITECH PROJECT, 2022
** Epi-MyTeams
** File description:
** get_cmd_list
*/

#include <unistd.h>
#include "get_command.h"
#include "reply_codes.h"
#include "logging_client.h"

int list_responses_list(char **tab, char *code_response)
{
    if (!strcmp(code_response, "30"))
        client_error_unknown_team(tab[1]);
    if (!strcmp(code_response, "31"))
        client_error_unknown_channel(tab[1]);
    if (!strcmp(code_response, "32"))
        client_error_unknown_thread(tab[1]);
    free(tab);
    return 0;
}

int list_responses(char **tab, char *code_response)
{
    if (!strcmp(code_response, "41"))
        for (int i = 0; tab[i + 6]; i = i + 6)
            client_print_teams(tab[i + 1], tab[i + 3], tab[i + 5]);
    if (!strcmp(code_response, "42"))
        for (int i = 0; tab[i + 6]; i = i + 6)
            client_team_print_channels(tab[i + 1], tab[i + 3], tab[i + 5]);
    if (!strcmp(code_response, "43"))
        for (int i = 0; tab[i + 10]; i = i + 10)
            client_channel_print_threads(tab[i + 1], tab[i + 3],
            atol(tab[i + 5]), tab[i + 7], tab[i + 9]);
    if (!strcmp(code_response, "43"))
        for (int i = 0; tab[i + 8]; i = i + 8)
            client_thread_print_replies(tab[i + 1],
            tab[i + 3], atol(tab[i + 5]), tab[i + 7]);
    return list_responses_list(tab, code_response);
}

int list(char *av, int socket)
{
    char code_response[3] = {0};
    char **tab_res = NULL;

    if (check_params(av) == 0)
        tab_res = send_command(av, tab_res, "LSTE ", socket);
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
    if (!strcmp(code_response, "13"))
        client_error_unauthorized();
    return list_responses(tab_res, code_response);
}
