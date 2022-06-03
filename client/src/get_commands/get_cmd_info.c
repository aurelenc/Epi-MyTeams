/*
** EPITECH PROJECT, 2022
** Epi-MyTeams
** File description:
** get_cmd_info
*/

#include <unistd.h>
#include "get_command.h"
#include "reply_codes.h"
#include "logging_client.h"

int info_responses(char **tab, char *code_response)
{
    if (!strcmp(code_response, "13"))
        client_error_unauthorized();
    if (!strcmp(code_response, "30"))
        client_error_unknown_team(tab[1]);
    if (!strcmp(code_response, "31"))
        client_error_unknown_channel(tab[1]);
    if (!strcmp(code_response, "32"))
        client_error_unknown_thread(tab[1]);
    if (!strcmp(code_response, "40"))
        client_print_user(tab[1], tab[2], atoi(tab[5]));
    if (!strcmp(code_response, "41"))
        client_print_team(tab[1], tab[2], tab[5]);
    if (!strcmp(code_response, "42"))
        client_print_channel(tab[1], tab[2], tab[5]);
    //if (!strcmp(code_response, "43")) @timestamp
    //    client_print_thread(tab[1], tab[2], tab[5], tab[7], tab[9]);
    // char const *thread_uuid,
    // char const *user_uuid,
    // time_t thread_timestamp,
    // char const *thread_title,
    // char const *thread_body);
    free(tab);
    return 0;
}

int info(char *av, int socket)
{
    char code_response[3] = {0};
    char **tab_res = NULL;

    if (check_params(av) == 0)
        tab_res = send_command(av, tab_res, "INFO ", socket);
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
    return info_responses(tab_res, code_response);
}
