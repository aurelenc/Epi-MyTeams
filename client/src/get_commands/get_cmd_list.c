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

int list_responses(char **tab, char *code_response)
{
    if (!strcmp(code_response, "13"))
        client_error_unauthorized();
    if (!strcmp(code_response, "41")) //print_list_of_user
        client_print_teams(tab[1], tab[3], tab[5]);
    if (!strcmp(code_response, "42")) //print_list_of_user
        client_team_print_channels(tab[1], tab[3], tab[5]);
    //if (!strcmp(code_response, "43")) //print_list_of_user @timestamp
    //    client_channel_print_threads(tab[1], tab[3], tab[5], tab[7], tab[9]);
        // char const *thread_uuid,
        // char const *user_uuid,
        // time_t thread_timestamp,
        // char const *thread_title,
        // char const *thread_body);
    //if (!strcmp(code_response, "44")) //print_list_of_user @timestamp
    //    client_thread_print_replies(tab[1], tab[3], tab[5], tab[7]);
        // char const *thread_uuid,
        // char const *user_uuid,
        // time_t reply_timestamp,
        // char const *reply_body);
    if (!strcmp(code_response, "30"))
        client_error_unknown_team(tab[1]);
    if (!strcmp(code_response, "31"))
        client_error_unknown_channel(tab[1]);
    if (!strcmp(code_response, "32"))
        client_error_unknown_thread(tab[1]);
    free(tab);
    return 0;
}

int list(char *av, int socket)
{
    char code_response[3] = {0};
    char **tab_res = NULL;

    if (check_params(av) == 0)
        tab_res = send_command(av, tab_res, "LSTE ", socket);
    else {
        printf("Command are not good use /help for more information !\n");
        return -1;
    }
    if (tab_res == NULL) {
        printf("Tab_res == NULL\n");
        free(tab_res);
        return -1;
    }
    strncpy(code_response, tab_res[0], 2);
    return list_responses(tab_res, code_response);
}
