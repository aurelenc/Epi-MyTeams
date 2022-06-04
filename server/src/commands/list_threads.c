/*
** EPITECH PROJECT, 2022
** Epi-MyTeams
** File description:
** list_threads
*/

#include "reply_codes.h"
#include "server.h"
#include "tables/threads/database_threads_search.h"
#include <stdio.h>
#include <string.h>

static void fill_message(TEAMS_A, node_t *it)
{
    char message[MAX_BUFF_SIZE + 1] = {0};

    while (it) {
        memset(message, 0, MAX_BUFF_SIZE);
        snprintf(message, MAX_BUFF_SIZE, "[\"%s\" \"%s\" \"%ld\" \"%s\" \"%s\"]",
        ((thread_t *)(it->data))->uuid,
        ((thread_t *)(it->data))->uuid, // To replace with thread creator
        ((thread_t *)(it->data))->timestamp,
        ((thread_t *)(it->data))->title,
        ((thread_t *)(it->data))->body);
        printf("%s\n", message);
        write_client_buff(PARAM_CID, message);
        it = it->next;
    }
}

int command_list_threads(TEAMS_A)
{
    node_t *iterator = 0;

    iterator = THIS_DB->threads->first;
    if (!iterator)
        return client_reply(PARAM_CID, PRINT_ALL_THREADS, EMPTY_REPLY);
    write_client_buff(PARAM_CID, "00:");
    fill_message(param, iterator);
    write_client_buff(PARAM_CID, "\n");
    return SUCCESS;
}
