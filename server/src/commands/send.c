/*
** EPITECH PROJECT, 2022
** Epi-MyTeams
** File description:
** send
*/

#include "reply_codes.h"
#include "server.h"
#include "tables/users/database_users_search.h"
#include "tables/discussions/database_discussions_search.h"
#include "tables/messages/database_messages_add.h"
#include "tables/discussions/database_discussions_add.h"
#include "tables/messages/message.h"
#include "tables/discussions/discussion.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void send_to_other_user(client_sock_t *clients, int id, char *uuid,
char *msg)
{
    char *reply =
    calloc(sizeof(char), strlen(uuid) + strlen(msg) + 12);

    if (!reply)
        exit(84);
    strcat(reply, "[ \"");
    strcat(reply, uuid);
    strcat(reply, "\" \"");
    strcat(reply, msg);
    strcat(reply, "\"]");
    client_reply(clients, id, GET_MESSAGE, reply);
    free(reply);
}

static void get_reply_msg(TEAMS_A, char *user_uuid, char *message_body)
{
    char *reply =
    calloc(sizeof(char), strlen(user_uuid) + strlen(message_body) + 12);

    if (!reply)
        exit(84);
    strcat(reply, "[ \"");
    strcat(reply, user_uuid);
    strcat(reply, "\" \"");
    strcat(reply, message_body);
    strcat(reply, "\"]");
    client_reply(PARAM_CID, SUCCESS, reply);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (!TEAMS_CLIENTS[i].socket || !TEAMS_CLIENTS[i].user)
            continue;
        if (strcmp(TEAMS_CLIENTS[i].user->uuid, user_uuid) == 0)
            send_to_other_user(TEAMS_CLIENTS, i, THIS_CLIENT.user->uuid,
            message_body);
    }
    free(reply);
}

static void add_msg_to_db(TEAMS_A,
user_t *user_one, user_t *user_two, id_t *ids)
{
    int *relation = calloc(sizeof(int), 2);
    discussion_t *disc = db_search_discussion_by_users_id(THIS_DB, ids);

    if (!relation)
        exit(84);
    if (disc) {
        relation[0] = 0;
        relation[1] = disc->id;
        db_add_msg(THIS_DB, msg_init(THIS_ARG[2], ids[1], relation));
    } else {
        disc = discussion_init(ids[0], ids[1]);
        db_add_discussion(THIS_DB, disc);
        relation[0] = 0;
        relation[1] = disc->id;
        db_add_msg(THIS_DB, msg_init(THIS_ARG[2], ids[1], relation));
    }
}

int command_send(TEAMS_A)
{
    user_t *user_one = 0;
    id_t *ids = calloc(sizeof(id_t), 2);
    char user_id_formatted[UUID_SIZE + 7] = {0};

    if (!THIS_CLIENT.user)
        return client_reply(PARAM_CID, FORBIDDEN, EMPTY_REPLY);
    if (param->arg.nb < 3)
        return client_reply(PARAM_CID, MISSING_PARAMETER, EMPTY_REPLY);
    else if (param->arg.nb > 3)
        return client_reply(PARAM_CID, INVALID_FORMAT, EMPTY_REPLY);
    user_one = db_search_user_by_uuid(THIS_DB, THIS_ARG[1]);
    if (!user_one) {
        snprintf(user_id_formatted, UUID_SIZE + 6, "[ \"%s\"]", THIS_ARG[1]);
        return client_reply(PARAM_CID, NOT_FOUND, user_id_formatted);
    }
    ids[0] = user_one->id;
    ids[1] = THIS_CLIENT.user->id;
    add_msg_to_db(TEAMS_PARAM, user_one, THIS_CLIENT.user, ids);
    get_reply_msg(TEAMS_PARAM, user_one->uuid, THIS_ARG[2]);
    return SUCCESS;
}
