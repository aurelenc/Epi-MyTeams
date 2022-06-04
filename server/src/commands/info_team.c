/*
** EPITECH PROJECT, 2022
** Epi-MyTeams
** File description:
** info_team
*/

#include "reply_codes.h"
#include "server.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static char *get_msg_reply(team_t *team, client_sock_t *clients)
{
    char *buff = calloc(sizeof(char),
    strlen(team->uuid) + strlen(team->name) + 16);

    strcat(buff, "00:");
    strcat(buff, "[ \"");
    strcat(buff, team->uuid);
    strcat(buff, "\" \"");
    strcat(buff, team->name);
    strcat(buff, "\" \"");
    strcat(buff, team->desc);
    strcat(buff, "\"]");
    printf("%s\n", buff);
    return (buff);
}

int command_info_team(TEAMS_A)
{
    char *message = get_msg_reply(THIS_CLIENT.team, TEAMS_CLIENTS);

    client_reply(PARAM_CID, PRINT_ALL_TEAMS, message);
    free(message);
    return SUCCESS;
}
