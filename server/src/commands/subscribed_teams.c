/*
** EPITECH PROJECT, 2022
** Epi-MyTeams
** File description:
** subscribed_teams
*/

#include "reply_codes.h"
#include "server.h"
#include "tables/users_x_teams/database_users_x_teams_multiple_search.h"
#include <string.h>
#include <time.h>
#include <stdio.h>

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

int command_subscribed_teams(TEAMS_A)
{
    database_t *new =
    db_search_teams_of_an_user_by_his_id(THIS_DB, THIS_CLIENT.user->id);
    node_t *iterator = 0;

    if (!new)
        return client_reply(PARAM_CID, PRINT_ALL_TEAMS, EMPTY_REPLY);
    iterator = new->teams->first;
    if (!iterator)
        return client_reply(PARAM_CID, PRINT_ALL_TEAMS, EMPTY_REPLY);
    write_client_buff(PARAM_CID, "41:");
    fill_message(param, iterator);
    write_client_buff(PARAM_CID, "\n");
    return PRINT_ALL_TEAMS;
}
