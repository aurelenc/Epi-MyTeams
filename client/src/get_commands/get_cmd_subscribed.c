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
    code_response[2] = '\0';
    if (!strcmp(code_response, "13"))
        client_error_unauthorized();

    if (!strcmp(code_response, "30"))
        client_error_unknown_team(tab_res[1]);
            // char const *team_uuid);

    if (!strcmp(code_response, "40")) //print_list_of_user
        client_print_users(tab_res[1], tab_res[3], atoi(tab_res[5]));
    // char const *user_uuid,
    // char const *user_name,
    // int user_status);

    if (!strcmp(code_response, "41")) //print_list_of_user
        client_print_teams(tab_res[1], tab_res[3], tab_res[5]);
    // char const *team_uuid,
    // char const *team_name,
    // char const *team_description);

    free(tab_res);
    return 0;
}
