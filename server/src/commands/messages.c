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
    char message[MAX_BUFF_SIZE + 1] = {0};

    while (it) {
        memset(message, 0, MAX_BUFF_SIZE);
        snprintf(message, MAX_BUFF_SIZE, "[\"%s\" \"%ld\" \"%s\"]",
        db_search_user_by_id(THIS_DB, ((msg_t *)(it->data))->id)->uuid,
        ((msg_t *)(it->data))->timestamp,
        ((msg_t *)(it->data))->content);
        printf("%s\n", message);
        write_client_buff(PARAM_CID, message);
        it = it->next;
    }
}

static int generate_messages(user_t *user_one, user_t *user_two, TEAMS_A)
{
    id_t user_pair[3] = {user_one->id, user_two->id, 0};
    discussion_t *disc =
    db_search_discussion_by_users_id(THIS_DB, user_pair);
    database_t *new = 0;
    node_t *iterator = 0;

    if (!disc)
        return client_reply(PARAM_CID, SUCCESS, EMPTY_REPLY);
    new = db_multiple_search_msg_by_discussion_id(THIS_DB, disc->id);
    if (!new)
        return client_reply(PARAM_CID, SUCCESS, EMPTY_REPLY);
    iterator = new->messages->first;
    if (!iterator)
        return client_reply(PARAM_CID, SUCCESS, EMPTY_REPLY);
    write_client_buff(PARAM_CID, "00:");
    fill_message(param, iterator);
    write_client_buff(PARAM_CID, "\n");
    return SUCCESS;
}

int command_messages(TEAMS_A)
{
    user_t *user_two = 0;
    char user_id_formatted[UUID_SIZE + 7] = {0};

    if (!THIS_CLIENT.user)
        return client_reply(PARAM_CID, FORBIDDEN, EMPTY_REPLY);
    if (param->arg.nb != 2)
        return client_reply(PARAM_CID, MISSING_PARAMETER, EMPTY_REPLY);
    user_two = db_search_user_by_uuid(THIS_DB, THIS_ARG[1]);
    if (!user_two) {
        sprintf(user_id_formatted, "[ \"%s\"]", THIS_ARG[1]);
        return client_reply(PARAM_CID, NOT_FOUND, user_id_formatted);
    }
    return generate_messages(THIS_CLIENT.user, user_two, param);
}
