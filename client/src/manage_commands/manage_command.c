/*
** EPITECH PROJECT, 2022
** Project
** File description:
** manage_command
*/

#include "get_command.h"

tab_command_sending_t tab_command_sending[] = {
    {"/unsubscribe", &unsubscribe_teams},
    {"/subscribe", &subscribe_teams},
    {"/subscribed", &subscribed},
    {"/send", &send_message},
    {"/help", &help},
    {"/logout", &logout_client},
    {"/login", &login_client},
    {"/use", &use},
    {"/info", &info},
    {"/list", &list},
    {"/messages", &messages},
    {"/create", &create},
    {"/user", &user},
    {"/users", &users},
    {"a b", NULL}
};

void get_rfds_command(char *command, char *av, int socket)
{
    //printf("Command = [%s], av = [%s]\n", command, av);
    for (int i = 0; tab_command_sending[i].cmd != NULL; i++)
        if (!strcmp(tab_command_sending[i].cmd, command))
            tab_command_sending[i].function(av, socket);
}

int parse_command(char *input, int socket)
{
    char *cmdClient = strtok(input, "\r\n");
    char *command = NULL;
    char *arguments = NULL;

    while (cmdClient) {
        command = strsep(&cmdClient, " \"");
        arguments = cmdClient;
        get_rfds_command(command, arguments, socket);
        cmdClient = strtok(NULL, "\r\t");
    }
    return (0);
}
