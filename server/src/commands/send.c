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

static void add_msg_to_db(TEAMS_A, user_t *user_one, user_t *user_two,
id_t *ids)
{
    int  *relation = calloc(sizeof(int), 2);
    discussion_t *disc = db_search_discussion_by_users_id(THIS_DB, ids);

    if (disc) {
        relation[0] = 0;
        relation[1] = disc->id;
        db_add_msg(THIS_DB, msg_init(llist_get_size(
            THIS_DB->messages), THIS_ARG[2], ids[1], relation));
    } else {
        disc = discussion_init(llist_get_size(THIS_DB->discussions),
        ids[0], ids[1]);
        db_add_discussion(THIS_DB, disc);
        relation[0] = 0;
        relation[1] = disc->id;
        db_add_msg(THIS_DB, msg_init(llist_get_size(
            THIS_DB->messages), THIS_ARG[2], ids[1], relation));
    }
    //send message to the client here
}

int command_send(TEAMS_A)
{
    user_t *user_one = 0;
    user_t *user_two = 0;
    id_t *ids = calloc(sizeof(id_t), 2);

    printf("[SERVER] SEND\n");
    //CHECK IF HE'S CONNECTED
    if (param->arg.nb < 3)
        return client_reply(PARAM_CID, MISSING_PARAMETER);
    else if (param->arg.nb > 3)
        return client_reply(PARAM_CID, INVALID_FORMAT);
    user_one = db_search_user_by_uuid(THIS_DB, THIS_ARG[1]);
    if (!user_one)
        return client_reply(PARAM_CID, NOT_FOUND);
    user_two = db_search_user_by_id(THIS_DB,
    THIS_CLIENT.user);
    ids[0] = user_one->id;
    ids[1] = user_two->id;
    add_msg_to_db(param, user_one, user_two, ids);
    return client_reply(PARAM_CID, SUCCESS);
}
