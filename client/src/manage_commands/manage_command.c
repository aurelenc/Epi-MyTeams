/*
** EPITECH PROJECT, 2022
** Project
** File description:
** manage_command
*/

#include "../../include/get_command.h"

tab_command_sending_t tab_command_sending[] = {
    {"/login", &log_client},
    {"a b", NULL}
};

void get_rfds_command(char *command, char *av, int socket)
{
    for (int i = 0; tab_command_sending[i].cmd != NULL; i++)
        if (!strcmp(tab_command_sending[i].cmd, command)) {
            printf("Argument are = [%s]\n", av);
            tab_command_sending[i].function(av, socket);
        }
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