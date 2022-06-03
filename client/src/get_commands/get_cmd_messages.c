/*
** EPITECH PROJECT, 2022
** Epi-MyTeams
** File description:
** get_cmd_message
*/

#include <unistd.h>
#include "get_command.h"
#include "reply_codes.h"
#include "logging_client.h"

int messages(char *av, int socket)
{
    char code_response[3];
    char **tab_response = NULL;

    if (check_params(av) == 1)
        tab_response = send_command(av, tab_response, "MSG ", socket);
    else {
        printf("Command are not good use /help for more information !\n");
        return -1;
    }
    strncpy(code_response, tab_response[0], 2);
    code_response[2] = '\0';
    if (!strcmp(code_response, "13"))
        client_error_unauthorized();

    //if (!strcmp(code_response, "??")) @timestamp  //print_list_of_user
    //    client_private_message_print_messages(tab_response[1], tab_response[3], tab_response[5]);
    // char const *sender_uuid,
    // time_t message_timestamp,
    // char const *message_body);

    if (!strcmp(code_response, "??"))
        client_error_unknown_user(tab_response[0]);
    // char const *user_uuid);

    free(tab_response);
    return 0;
}
