/*
** EPITECH PROJECT, 2022
** Project
** File description:
** manage_command
*/

#include "get_command.h"

tab_command_sending_t tab_command_sending[] = {
    {"/unsubscribe", &unsubscribe_teams},
    {"/subscribed", &subscribe_teams},
    {"/send", &send_message},
    {"/logout", &logout_client},
    {"/login", &login_client},
    {"/use_thread", &use_threads},
    {"/use_team", &use_teams},
    {"/use_channel", &use_channel},
    {"/info_thread", &infos_thread},
    {"/info_team", &infos_team},
    {"/info_channel", &infos_channel},
    {"/info_user", &infos_user},
    {"/list_users", &list_users},
    {"/list_users_messages", &list_users_messages},
    {"/list_user_subscribed", &list_user_subscribed},
    {"/list_threads", &list_threads},
    {"/list_teams", &list_teams},
    {"/list_teams_subscribed", &list_teams_subscribed},
    {"/list_channels", &list_channels},
    {"/create_thread", &create_thread},
    {"/create_teams", &create_teams},
    {"/create_channe", &create_channel},
    {"a b", NULL}
};

void get_rfds_command(char *command, char *av, int socket)
{
    printf("Command = [%s], av = [%s]\n", command, av);
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
