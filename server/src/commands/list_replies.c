/*
** EPITECH PROJECT, 2022
** Epi-MyTeams
** File description:
** list_replies
*/

#include "reply_codes.h"
#include "server.h"
#include "tables/messages/database_messages_search.h"
#include "tables/users/database_users_search.h"
#include "tables/threads/database_threads_search.h"
#include <stdio.h>
#include <string.h>

static void fill_message(TEAMS_A, node_t *it)
{
    char message[MAX_BUFF_SIZE + 1] = {0};

    while (it) {
        if (((msg_t *)it->data)->thread_id != THIS_CLIENT.thread->id)
            continue;
        memset(message, 0, MAX_BUFF_SIZE);
        snprintf(message, MAX_BUFF_SIZE, "[\"%s\" \"%s\" \"%ld\" \"%s\"]",
        db_search_msg_by_id(THIS_DB, ((msg_t *)(it->data))->thread_id)->uuid,
        db_search_user_by_id(THIS_DB, ((msg_t *)(it->data))->user_id)->uuid,
        ((msg_t *)(it->data))->timestamp,
        ((msg_t *)(it->data))->content);
        printf("%s\n", message);
        write_client_buff(PARAM_CID, message);
        it = it->next;
    }
}

int command_list_replies(TEAMS_A)
{
    node_t *iterator = 0;

    iterator = THIS_DB->messages->first;
    if (!iterator)
        return client_reply(PARAM_CID, PRINT_ALL_REPLIES, EMPTY_REPLY);
    write_client_buff(PARAM_CID, "44:");
    fill_message(param, iterator);
    write_client_buff(PARAM_CID, "\n");
    return SUCCESS;
}
