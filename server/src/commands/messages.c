/*
** EPITECH PROJECT, 2022
** Epi-MyTeams
** File description:
** messages
*/

#include "reply_codes.h"
#include "server.h"
#include "tables/users/database_users_search.h"
#include "tables/discussions/database_discussions_search.h"
#include "tables/messages/database_messages_multiple_search_relation.h"
#include "tables/messages/message.h"
#include <string.h>
#include <time.h>
#include <stdio.h>

static void fill_message(command_param_t *param, node_t *it)
{
    char message[MAX_BUFF_SIZE] = {0};

    while (it) {
        memset(message, 0, MAX_BUFF_SIZE);
        snprintf(message, MAX_BUFF_SIZE, "[\"%ld\" \"%s\"",
        ((msg_t *)(it->data))->timestamp,
        ((msg_t *)(it->data))->content);
        printf("%s\n", message);
        if (it->next)
            strcpy(message, " ");
        write_client_buff(param->clients, param->id, message);
        it = it->next;
    }
}

static int generate_messages(user_t *user_one, user_t *user_two,
command_param_t *param)
{
    id_t user_pair[3] = {user_one->id, user_two->id, 0};
    discussion_t *disc =
    db_search_discussion_by_users_id(param->srv->db, user_pair);
    database_t *new = 0;
    node_t *iterator = 0;

    if (!disc)
        return client_reply_success(PARAM_CID, "");
    new = db_multiple_search_msg_by_discussion_id(param->srv->db, disc->id);
    if (!new)
        return client_reply_success(PARAM_CID, "");
    iterator = new->messages->first;
    if (!iterator)
        return client_reply_success(param->clients, param->id, "");
    write_client_buff(param->clients, param->id, "00:");
    fill_message(param, iterator);
    write_client_buff(param->clients, param->id, "\n");
    return SUCCESS;
}

int command_messages(command_param_t *param)
{
    user_t *user_one = 0;
    user_t *user_two = 0;

    if (param->arg.nb != 2)
        return client_reply(param->clients, param->id, MISSING_PARAMETER);
    user_two = db_search_user_by_uuid(param->srv->db, param->arg.array[1]);
    if (!user_two)
        return client_reply(param->clients, param->id, NOT_FOUND);
    user_one = db_search_user_by_id(param->srv->db,
    param->clients[param->id].user);
    return generate_messages(user_one, user_two, param);
}
