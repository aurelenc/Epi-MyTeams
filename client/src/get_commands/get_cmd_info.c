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

int info(char *av, int socket)
{
    char code_response[3];
    char **tab_response = NULL;

    if (check_params(av) == 0)
        tab_response = send_command(av, tab_response, "INFO ", socket);
    else {
        printf("Command are not good use /help for more information !\n");
        return -1;
    }
    strncpy(code_response, tab_response[0], 2);
    code_response[2] = '\0';
    if (!strcmp(code_response, "13"))
        client_error_unauthorized();

    if (!strcmp(code_response, "30"))
        client_error_unknown_team(tab_response[1]);
    // char const *team_uuid);

    if (!strcmp(code_response, "31"))
        client_error_unknown_channel(tab_response[1]);
    // char const *channel_uuid);

    if (!strcmp(code_response, "32"))
        client_error_unknown_thread(tab_response[1]);
    // char const *thread_uuid);

    if (!strcmp(code_response, "40"))
        client_print_user(tab_response[1], tab_response[2], atoi(tab_response[5]));
    // char const *user_uuid,
    // char const *user_name,
    // int user_status);

    if (!strcmp(code_response, "41"))
        client_print_team(tab_response[1], tab_response[2], tab_response[5]);
    // char const *team_uuid,
    // char const *team_name,
    // char const *team_description);

    if (!strcmp(code_response, "42"))
        client_print_channel(tab_response[1], tab_response[2], tab_response[5]);
    // char const *channel_uuid,
    // char const *channel_name,
    // char const *channel_description);

    //if (!strcmp(code_response, "43")) @timestamp
    //    client_print_thread(tab_response[1], tab_response[2], tab_response[5], tab_response[7], tab_response[9]);
    // char const *thread_uuid,
    // char const *user_uuid,
    // time_t thread_timestamp,
    // char const *thread_title,
    // char const *thread_body);


    free(tab_response);
    return 0;
}
