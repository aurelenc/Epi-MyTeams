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

static user_t *get_user(TEAMS_A)
{
    user_t *user = db_search_user_by_pseudo(THIS_DB,
    THIS_ARG[1]);

    if (!user) {
        user = user_init(llist_get_size(THIS_DB->users),
        THIS_ARG[1], "");
        db_add_user(THIS_DB, user);
        server_event_user_created(user->uuid, user->pseudo);
    } else
        server_event_user_logged_in(user->uuid);
    return user;
}

int command_login(TEAMS_A)
{
    char success_buff[MAX_BUFF_SIZE] = {0};
    char *reply = 0;
    user_t *user = 0;

    printf("[SERVER] LOGIN\n");
    if (param->arg.nb < 2) {
        return client_reply(TEAMS_CLIENTS, param->id, MISSING_PARAMETER);
    } else if (param->arg.nb > 2) {
        return client_reply(TEAMS_CLIENTS, param->id, INVALID_FORMAT);
    }
    user = get_user(param);
    THIS_CLIENT.user = user->id;
    reply = get_reply_msg(user->uuid, user->pseudo);
    sprintf(success_buff, reply_codes[get_reply(SUCCESS)].message, reply);
    free(reply);
    return client_reply_success(TEAMS_CLIENTS, param->id, success_buff);
}
