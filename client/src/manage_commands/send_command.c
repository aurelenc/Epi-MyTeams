/*
** EPITECH PROJECT, 2022
** Epi-MyTeams
** File description:
** send_command
*/

#include "client.h"
#include "get_command.h"
#include "reply_codes.h"

char **send_command(char *av, char **tab_response, char *command, int socket)
{
    char buff[4096];
    char response[2];

    memset(buff, 0, 4096);
    make_command_rfc_compatible(buff, command, av);
    write(socket, buff, strlen(buff));
    memset(buff, 0, 4096);
    if (read(socket, buff, 4096) == 0) {
        printf("Client is deconnected !\n");
        exit (0);
    }
    if (client_reply(atoi(strncpy(response, buff, 2)), tab_response, buff)
    == -42)
        if (read(socket, buff, 4096) == 0) {
            printf("Client is deconnected !\n");
            exit (0);
        }
    if (strlen(buff) > 4)
        tab_response = parse_response(buff, 2);
    return tab_response;
}
