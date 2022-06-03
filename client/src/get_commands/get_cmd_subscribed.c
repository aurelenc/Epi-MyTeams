/*
** EPITECH PROJECT, 2022
** Epi-MyTeams
** File description:
** get_cmd_subscribed
*/

#include <unistd.h>
#include "get_command.h"
#include "reply_codes.h"
#include "logging_client.h"

int subscribed_responses(char **tab, char *code_response)
{
    if (!strcmp(code_response, "13"))
        client_error_unauthorized();
    if (!strcmp(code_response, "30"))
        client_error_unknown_team(tab[1]);
    if (!strcmp(code_response, "40")) //print_list_of_user
        client_print_users(tab[1], tab[3], atoi(tab[5]));
    if (!strcmp(code_response, "41")) //print_list_of_user
        client_print_teams(tab[1], tab[3], tab[5]);
    free(tab);
    return 0;
}

int subscribed(char *av, int socket)
{
    char code_response[3];
    char **tab_res = NULL;

    if (check_params(av) <= 1)
        tab_res = send_command(av, tab_res, "SUBT ", socket);
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
    return subscribed_responses(tab_res, code_response);
}
