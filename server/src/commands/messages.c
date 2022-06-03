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

static void fill_message(TEAMS_A, node_t *it)
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
        write_client_buff(TEAMS_CLIENTS, param->id, message);
        it = it->next;
    }
}

static int generate_messages(user_t *user_one, user_t *user_two,
TEAMS_A)
{
    id_t user_pair[3] = {user_one->id, user_two->id, 0};
    discussion_t *disc =
    db_search_discussion_by_users_id(THIS_DB, user_pair);
    database_t *new = 0;
    node_t *iterator = 0;

    if (!disc)
        return client_reply_success(PARAM_CID, "");
    new = db_multiple_search_msg_by_discussion_id(THIS_DB, disc->id);
    if (!new)
        return client_reply_success(PARAM_CID, "");
    iterator = new->messages->first;
    if (!iterator)
        return client_reply_success(TEAMS_CLIENTS, param->id, "");
    write_client_buff(TEAMS_CLIENTS, param->id, "00:");
    fill_message(param, iterator);
    write_client_buff(TEAMS_CLIENTS, param->id, "\n");
    return SUCCESS;
}

int command_messages(TEAMS_A)
{
    user_t *user_one = 0;
    user_t *user_two = 0;

    if (param->arg.nb != 2)
        return client_reply(TEAMS_CLIENTS, param->id, MISSING_PARAMETER);
    user_two = db_search_user_by_uuid(THIS_DB, THIS_ARG[1]);
    if (!user_two)
        return client_reply(TEAMS_CLIENTS, param->id, NOT_FOUND);
    user_one = db_search_user_by_id(THIS_DB,
    THIS_CLIENT.user);
    return generate_messages(user_one, user_two, param);
}
