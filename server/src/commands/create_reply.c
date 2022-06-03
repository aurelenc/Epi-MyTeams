/*
** EPITECH PROJECT, 2022
** Epi-MyTeams
** File description:
** create_reply
*/

#include "logging_server.h"
#include "reply_codes.h"
#include "server.h"
#include "tables/teams/database_teams_search.h"
#include "tables/users_x_teams/database_users_x_teams_multiple_search.h"
#include "tables/users_x_teams/database_users_x_teams_search.h"
#include "tables/users/database_users_search.h"
#include "tables/threads/database_threads_search.h"
#include "tables/messages/database_messages_add.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static bool is_in_team(command_param_t *param)
{
    id_pair_t pair;
    id_pair_t *search = 0;

    if (!THIS_CLIENT.team)
        return false;
    pair.team_id = THIS_CLIENT.team->id;
    pair.user_id = THIS_CLIENT.user->id;
    search = db_search_user_team_by_pair(param->srv->db, &pair);
    if (!search)
        return false;
    return true;
}

static int *get_relation(int thread_id, int discussion_id)
{
    int *relation = calloc(sizeof(int), 2);

    if (!relation)
        exit(84);
    relation[0] = thread_id;
    relation[1] = discussion_id;
    return relation;
}

int command_create_reply(TEAMS_A)
{
    msg_t *msg = 0;
    int *relation = 0;

    if (param->arg.nb < 2) {
        return client_reply(param->clients, param->id, MISSING_PARAMETER);
    } else if (param->arg.nb > 2) {
        return client_reply(param->clients, param->id, INVALID_FORMAT);
    }
    if (!is_in_team(param))
        return client_reply(PARAM_CID, FORBIDDEN);
    relation = get_relation(THIS_CLIENT.thread->id, 0);
    msg = msg_init(param->arg.array[1], THIS_CLIENT.user->id, relation);
    db_add_msg(THIS_DB, msg);
    server_event_reply_created(THIS_CLIENT.thread->uuid,
    THIS_CLIENT.user->uuid, msg->content);
    //SEND HERE A MESSAGE TO ALL USERS SUBSCRIBED TO THE TEAM
    free(relation);
    return NOT_IMPLEMENTED;
}
