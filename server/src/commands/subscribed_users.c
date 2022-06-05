/*
** EPITECH PROJECT, 2022
** Epi-MyTeams
** File description:
** subscribed_users
*/

#include "reply_codes.h"
#include "server.h"
#include "tables/users_x_teams/database_users_x_teams_multiple_search.h"
#include "tables/teams/database_teams_search.h"
#include <string.h>
#include <time.h>
#include <stdio.h>

#include "tables/users_x_teams/users_x_teams.h"

static char *is_user_connected(client_sock_t *clients, unsigned int user_id)
{
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i].user && clients[i].user->id == user_id)
            return "1";
    }
    return "0";
}

static void fill_message(TEAMS_A, node_t *it)
{
    char message[MAX_BUFF_SIZE + 1] = {0};

    while (it) {
        memset(message, 0, MAX_BUFF_SIZE);
        snprintf(message, MAX_BUFF_SIZE, "[\"%s\" \"%s\" \"%s\"]",
        ((user_t *)(it->data))->uuid,
        ((user_t *)(it->data))->pseudo,
        is_user_connected(TEAMS_CLIENTS, ((user_t *)(it->data))->id));
        printf("%s\n", message);
        write_client_buff(PARAM_CID, message);
        it = it->next;
    }
}

int command_subscribed_users(TEAMS_A)
{
    char buff[MAX_BUFF_SIZE + 1];
    team_t *team = db_search_team_by_uuid(THIS_DB, THIS_ARG[1]);
    database_t *new = 0;
    node_t *iterator = 0;

    if (!team) {
        snprintf(buff, MAX_BUFF_SIZE, "[ \"%s\"]", THIS_ARG[1]);
        return client_reply(PARAM_CID, UNKNOWN_TEAM, buff);
    }
    new = db_search_users_of_a_team_by_its_id(THIS_DB, THIS_CLIENT.user->id);
    if (!new)
        return client_reply(PARAM_CID, PRINT_ALL_USERS, EMPTY_REPLY);
    iterator = new->users->first;
    if (!iterator)
        return client_reply(PARAM_CID, PRINT_ALL_USERS, EMPTY_REPLY);
    write_client_buff(PARAM_CID, "40:");
    fill_message(param, iterator);
    write_client_buff(PARAM_CID, "\n");
    return PRINT_ALL_USERS;
}
