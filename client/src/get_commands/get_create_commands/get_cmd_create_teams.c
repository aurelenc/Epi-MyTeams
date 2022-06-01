/*
** EPITECH PROJECT, 2022
** My_Teams
** File description:
** get_cmd_create_teams
*/



#include <unistd.h>
#include "get_command.h"
#include "reply_codes.h"
#include "logging_client.h"

int create_teams(char *av, int socket)
{
    char buff[4096];
    char response[2];
    char **tab_response;

    memset(buff, 0, 4096);
    if (av == NULL)
        return -1;
    if (check_params(av) == 1) { //check_parameters
        make_command_rfc_compatible(buff, "CRTE ", av);
        write(socket, buff, strlen(buff));
        memset(buff, 0, 4096);
        if (read(socket, buff, 4096) == 0) {
            printf("Client is deconnected !\n");
            exit (0);
        }
        client_reply(atoi(strncpy(response, buff, 2)));
        if (strlen(buff) > 4) {
            tab_response = parse_response(buff, 2);
            client_event_logged_in(tab_response[1], tab_response[3]);
        }
    } else {
        printf("Command are not good use /help for more information !\n");
    }
    return 0;
}
