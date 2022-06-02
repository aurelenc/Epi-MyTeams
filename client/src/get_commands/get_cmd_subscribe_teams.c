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

int subscribe_teams(char *av, int socket)
{
    char code_response[3];
    char **tab_response = NULL;


    if (check_params(av) == 1)
        tab_response = send_command(av, tab_response, "SUB ", socket);
    else
        printf("Command are not good use /help for more information !\n");
    strncpy(code_response, tab_response[0], 2);
    code_response[2] = '\0';
    if (!strcmp(code_response, "14"))
        client_error_unauthorized();

    if (!strcmp(code_response, "40")) //print_list_of_user
        client_print_users(tab_response[1], tab_response[3], atoi(tab_response[5]));
    // char const *team_uuid,
    // char const *team_name,
    // char const *team_description);
    if (!strcmp(code_response, "41")) //print_list_of_user
        client_print_teams(tab_response[1], tab_response[3], tab_response[5]);
    // char const *team_uuid,
    // char const *team_name,
    // char const *team_description);
    if (!strcmp(code_response, "30"))
        client_error_unknown_team(tab_response[1]);
    // char const *team_uuid
    if (!strcmp(code_response, "02"))
        client_print_subscribed(tab_response[1], tab_response[3]);
    // char const *user_uuid
    // char const *team_uuid);


    free(tab_response);
    return 0;
}
