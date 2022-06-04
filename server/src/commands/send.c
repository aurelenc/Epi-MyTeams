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

static char *get_reply_msg(char *user_uuid, char *message_body)
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
    return (reply);
}

static void add_msg_to_db(
TEAMS_A, user_t *user_one, user_t *user_two, id_t *ids)
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
    //send message to the client here
}

int command_send(TEAMS_A)
{
    user_t *user_one = 0;
    id_t *ids = calloc(sizeof(id_t), 2);
    char *message;

    printf("[SERVER] SEND\n");
    if (!THIS_CLIENT.user)
        return client_reply(PARAM_CID, FORBIDDEN, EMPTY_REPLY);
    if (param->arg.nb < 3)
        return client_reply(PARAM_CID, MISSING_PARAMETER, EMPTY_REPLY);
    else if (param->arg.nb > 3)
        return client_reply(PARAM_CID, INVALID_FORMAT, EMPTY_REPLY);
    user_one = db_search_user_by_uuid(THIS_DB, THIS_ARG[1]);
    if (!user_one)
        return client_reply(PARAM_CID, NOT_FOUND, EMPTY_REPLY);
    ids[0] = user_one->id;
    ids[1] = THIS_CLIENT.user->id;
    add_msg_to_db(TEAMS_PARAM, user_one, THIS_CLIENT.user, ids);
    message = get_reply_msg(user_one->uuid, THIS_ARG[2]);
    client_reply(PARAM_CID, SUCCESS, message);
    free(message);
    return SUCCESS;
}
