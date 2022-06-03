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

static char *get_reply_msg(char *user_uuid, char *user_name)
{
    char *reply =
    calloc(sizeof(char), strlen(user_uuid) + strlen(user_name) + 12);

    strcat(reply, "[ \"");
    strcat(reply, user_uuid);
    strcat(reply, "\" \"");
    strcat(reply, user_name);
    strcat(reply, "\"]");
    return (reply);
}

int command_logout(TEAMS_A)
{
    char success_buff[MAX_BUFF_SIZE] = {0};
    char *reply = 0;

    if (!THIS_CLIENT.user)
        return client_reply(PARAM_CID, FORBIDDEN);
    reply = get_reply_msg(THIS_CLIENT.user->uuid, THIS_CLIENT.user->pseudo);
    sprintf(success_buff, reply_codes[get_reply(SUCCESS)].message, reply);
    free(reply);
    server_event_user_logged_out(THIS_CLIENT.user->uuid);
    THIS_CLIENT.user = 0;
    THIS_CLIENT.team = 0;
    THIS_CLIENT.channel = 0;
    THIS_CLIENT.thread = 0;
    return client_reply_success(PARAM_CID, success_buff);
}
