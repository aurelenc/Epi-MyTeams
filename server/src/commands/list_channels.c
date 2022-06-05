/*
** EPITECH PROJECT, 2022
** Epi-MyTeams
** File description:
** list_channels
*/

#include "reply_codes.h"
#include "server.h"
#include "tables/channels/database_channels_search.h"
#include <stdio.h>
#include <string.h>

static void fill_message(TEAMS_A, node_t *it)
{
    char message[MAX_BUFF_SIZE + 1] = {0};

    while (it) {
        memset(message, 0, MAX_BUFF_SIZE);
        snprintf(message, MAX_BUFF_SIZE, "[\"%s\" \"%s\" \"%s\"]",
        ((channel_t *)(it->data))->uuid,
        ((channel_t *)(it->data))->name,
        ((channel_t *)(it->data))->desc);
        printf("%s\n", message);
        write_client_buff(PARAM_CID, message);
        it = it->next;
    }
}

int command_list_channels(TEAMS_A)
{
    node_t *iterator = 0;

    iterator = THIS_DB->channels->first;
    if (!iterator)
        return client_reply(PARAM_CID, PRINT_ALL_CHANNELS, EMPTY_REPLY);
    write_client_buff(PARAM_CID, "42:");
    fill_message(param, iterator);
    write_client_buff(PARAM_CID, "\n");
    return SUCCESS;
}
