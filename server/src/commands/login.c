/*
** EPITECH PROJECT, 2022
** Epi-MyTeams
** File description:
** login
*/

#include "reply_codes.h"
#include "server.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tables/users/user.h"
#include "tables/users/database_users_add.h"
#include "tables/users/database_users_search.h"
#include "logging_server.h"

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
            client_reply(param->clients, i, GET_LOGI, reply);
    }
    return (SUCCESS);
}

static user_t *get_user(TEAMS_A)
{
    user_t *user = db_search_user_by_pseudo(THIS_DB, THIS_ARG[1]);

    if (!user) {
        user = user_init(THIS_ARG[1], "");
        db_add_user(THIS_DB, user);
        server_event_user_created(user->uuid, user->pseudo);
    }
    server_event_user_logged_in(user->uuid);
    return user;
}

int command_login(TEAMS_A)
{
    user_t *user = 0;

    printf("[SERVER] LOGIN\n");
    if (param->arg.nb < 2) {
        return client_reply(PARAM_CID, MISSING_PARAMETER, EMPTY_REPLY);
    } else if (param->arg.nb > 2) {
        return client_reply(PARAM_CID, INVALID_FORMAT, EMPTY_REPLY);
    }
    user = get_user(param);
    THIS_CLIENT.user = user;
    return send_reply_msg(param, user->uuid, user->pseudo);
}
