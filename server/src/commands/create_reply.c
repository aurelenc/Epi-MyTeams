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

static bool is_cli_in_team(database_t *db, client_sock_t *client,
team_t *team)
{
    id_pair_t pair;
    id_pair_t *search = 0;

    if (!team)
        return false;
    pair.team_id = team->id;
    pair.user_id = client->user->id;
    search = db_search_user_team_by_pair(db, &pair);
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

static char *get_success(TEAMS_A, msg_t *msg)
{
    int len = strlen(THIS_CLIENT.team->uuid) + strlen(THIS_CLIENT.thread->uuid)
    + strlen(THIS_CLIENT.user->uuid) + strlen(msg->content) + 20;
    char *buff = calloc(sizeof(char), len);

    snprintf(buff, len, "[ \"%s\" \"%s\" \"%s\" \"%s\"]\n",
    THIS_CLIENT.team->uuid, THIS_CLIENT.thread->uuid, THIS_CLIENT.user->uuid,
    msg->content);
    printf("%s\n", buff);
    return (buff);
}

static msg_t *create_msg(TEAMS_A)
{
    msg_t *msg = 0;
    int *relation = 0;

    relation = get_relation(THIS_CLIENT.thread->id, 0);
    msg = msg_init(param->arg.array[1], THIS_CLIENT.user->id, relation);
    free(relation);
    db_add_msg(THIS_DB, msg);
    server_event_reply_created(THIS_CLIENT.thread->uuid,
    THIS_CLIENT.user->uuid, msg->content);
    return msg;
}

int command_create_reply(TEAMS_A)
{
    char *buff = 0;

    if (param->arg.nb < 2) {
        return client_reply(param->clients, param->id, MISSING_PARAMETER, "");
    } else if (param->arg.nb > 2) {
        return client_reply(param->clients, param->id, INVALID_FORMAT, "");
    }
    if (!is_cli_in_team(THIS_DB, &THIS_CLIENT, THIS_CLIENT.team))
        return client_reply(PARAM_CID, FORBIDDEN, EMPTY_REPLY);
    buff = get_success(param, create_msg(param));
    client_reply(param->clients, param->id, CREATE_REPLY, buff);
    free(buff);
    return CREATE_REPLY;
}
