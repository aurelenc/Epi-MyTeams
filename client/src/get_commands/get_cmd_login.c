/*
** EPITECH PROJECT, 2022
** My_Teams
** File description:
** get_cmd_login
*/

#include <unistd.h>
#include "get_command.h"
#include "reply_codes.h"
#include "logging_client.h"

char **send_command(char *av, char **tab_response, char *command, int socket)
{
    char buff[4096];
    char response[2];

    memset(buff, 0, 4096);
    make_command_rfc_compatible(buff, command, av);
    write(socket, buff, strlen(buff));
    memset(buff, 0, 4096);
    printf("test021\n");
    if (read(socket, buff, 4096) == 0) {
        printf("Client is deconnected !\n");
        exit (0);
    }
    printf("test022\n");
    client_reply(atoi(strncpy(response, buff, 2)));
    printf("buff = [%s]\n", buff);
    if (strlen(buff) > 4) {
        printf("test023\n");
        tab_response = parse_response(buff, 2);
        printf("test024\n");
        printf("tab1 = [%s], tab2 = [%s]\n", tab_response[1], tab_response[3]);
        client_event_logged_in(tab_response[1], tab_response[3]);
        printf("test025\n");
    }
    return tab_response;
}

int login_client(char *av, int socket)
{
    char **tab_response = NULL;

    if (av == NULL)
        return -1;
    printf("test01\n");
    if (check_params(av) == 1) {
        printf("test02\n");
        tab_response = send_command(av, tab_response, "/LOGI ", socket);
        printf("test03\n");
    } else {
        printf("Command are not good use /help for more information !\n");
    }
    return 0;
}
