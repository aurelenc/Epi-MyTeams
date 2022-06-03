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

int list(char *av, int socket)
{
    char code_response[3];
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
    code_response[2] = '\0';
    if (!strcmp(code_response, "13"))
        client_error_unauthorized();


    if (!strcmp(code_response, "41")) //print_list_of_user
        client_print_teams(tab_res[1], tab_res[3], tab_res[5]);
    // char const *team_uuid,
    // char const *team_name,
    // char const *team_description);



     if (!strcmp(code_response, "42")) //print_list_of_user
        client_team_print_channels(tab_res[1], tab_res[3], tab_res[5]);
        // char const *channel_uuid,
        // char const *channel_name,
        // char const *channel_description);

    //if (!strcmp(code_response, "43")) //print_list_of_user @timestamp
    //    client_channel_print_threads(tab_res[1], tab_res[3], tab_res[5], tab_res[7], tab_res[9]);
        // char const *thread_uuid,
        // char const *user_uuid,
        // time_t thread_timestamp,
        // char const *thread_title,
        // char const *thread_body);

    //if (!strcmp(code_response, "44")) //print_list_of_user @timestamp
    //    client_thread_print_replies(tab_res[1], tab_res[3], tab_res[5], tab_res[7]);
        // char const *thread_uuid,
        // char const *user_uuid,
        // time_t reply_timestamp,
        // char const *reply_body);

    if (!strcmp(code_response, "30"))
        client_error_unknown_team(tab_res[1]);
        /// char const *team_uuid);

    if (!strcmp(code_response, "31"))
        client_error_unknown_channel(tab_res[1]);
        // char const *channel_uuid);

    if (!strcmp(code_response, "32"))
        client_error_unknown_thread(tab_res[1]);
        // char const *thread_uuid);





    free(tab_res);
    return 0;
}
