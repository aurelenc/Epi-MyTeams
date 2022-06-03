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

static void add_msg_to_db(command_param_t *param, user_t *user_one, user_t *user_two,
id_t *ids)
{
    int  *relation = calloc(sizeof(int), 2);
    discussion_t *disc = db_search_discussion_by_users_id(param->srv->db, ids);

    if (disc) {
        relation[0] = 0;
        relation[1] = disc->id;
        db_add_msg(param->srv->db, msg_init(llist_get_size(
            param->srv->db->messages), param->arg.array[2], ids[1], relation));
    } else {
        disc = discussion_init(llist_get_size(param->srv->db->discussions),
        ids[0], ids[1]);
        db_add_discussion(param->srv->db, disc);
        relation[0] = 0;
        relation[1] = disc->id;
        db_add_msg(param->srv->db, msg_init(llist_get_size(
            param->srv->db->messages), param->arg.array[2], ids[1], relation));
    }
    //send message to the client here
}

int command_send(command_param_t *param)
{
    user_t *user_one = 0;
    id_t *ids = calloc(sizeof(id_t), 2);

    printf("[SERVER] SEND\n");
    if (!THIS_CLIENT.user)
        return client_reply(PARAM_CID, FORBIDDEN);
    if (param->arg.nb < 3)
        return client_reply(param->clients, param->id, MISSING_PARAMETER);
    else if (param->arg.nb > 3)
        return client_reply(param->clients, param->id, INVALID_FORMAT);
    user_one = db_search_user_by_uuid(param->srv->db, param->arg.array[1]);
    if (!user_one)
        return client_reply(param->clients, param->id, NOT_FOUND);
    ids[0] = user_one->id;
    ids[1] = THIS_CLIENT.user->id;
    add_msg_to_db(param, user_one, THIS_CLIENT.user, ids);
    return client_reply(param->clients, param->id, SUCCESS);
}
