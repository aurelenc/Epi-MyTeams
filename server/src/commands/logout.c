/*
** EPITECH PROJECT, 2022
** Epi-MyTeams
** File description:
** logout
*/

#include "reply_codes.h"
#include "server.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "logging_server.h"
#include "tables/users/database_users_search.h"

static int send_reply_msg(TEAMS_A, char *user_uuid, char *user_name)
{
    int len = strlen(user_uuid) + strlen(user_name) + 12;
    char *reply = calloc(sizeof(char), len);

    snprintf(reply, len, "[ \"%s\" \"%s\"]", user_uuid, user_name);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (TEAMS_CLIENTS[i].socket == 0 || !TEAMS_CLIENTS[i].user)
            continue;
        if (i == param->id)
            client_reply(param->clients, i, SUCCESS, reply);
        else
            client_reply(param->clients, i, GET_LOGO, reply);
    }
    return (SUCCESS);
}

int command_logout(TEAMS_A)
{
    if (!THIS_CLIENT.user)
        return client_reply(PARAM_CID, FORBIDDEN, EMPTY_REPLY);
    server_event_user_logged_out(THIS_CLIENT.user->uuid);
    send_reply_msg(param, THIS_CLIENT.user->uuid, THIS_CLIENT.user->pseudo);
    THIS_CLIENT.user = 0;
    THIS_CLIENT.team = 0;
    THIS_CLIENT.channel = 0;
    THIS_CLIENT.thread = 0;
    return SUCCESS;
}
