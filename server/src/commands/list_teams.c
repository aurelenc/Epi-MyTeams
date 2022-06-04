/*
** EPITECH PROJECT, 2022
** Epi-MyTeams
** File description:
** list_teams
*/

#include "reply_codes.h"
#include "server.h"
#include "tables/teams/database_teams_search.h"
#include <stdio.h>
#include <string.h>

static void fill_message(TEAMS_A, node_t *it)
{
    char message[MAX_BUFF_SIZE + 1] = {0};

    while (it) {
        memset(message, 0, MAX_BUFF_SIZE);
        snprintf(message, MAX_BUFF_SIZE, "[\"%s\" \"%s\" \"%s\"]",
        ((team_t *)(it->data))->uuid,
        ((team_t *)(it->data))->name,
        ((team_t *)(it->data))->desc);
        printf("%s\n", message);
        write_client_buff(PARAM_CID, message);
        it = it->next;
    }
}

int command_list_teams(TEAMS_A)
{
    node_t *iterator = 0;

    iterator = THIS_DB->teams->first;
    if (!iterator)
        return client_reply(PARAM_CID, PRINT_ALL_TEAMS, EMPTY_REPLY);
    write_client_buff(PARAM_CID, "00:");
    fill_message(param, iterator);
    write_client_buff(PARAM_CID, "\n");
    return SUCCESS;
}
