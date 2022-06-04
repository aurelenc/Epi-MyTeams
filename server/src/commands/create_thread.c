/*
** EPITECH PROJECT, 2022
** Epi-MyTeams
** File description:
** create_thread
*/

#include "logging_server.h"
#include "reply_codes.h"
#include "server.h"
#include "tables/users_x_teams/database_users_x_teams_search.h"
#include "tables/threads/database_threads_add.h"
#include "tables/threads/database_threads_multiple_search.h"
#include "tables/threads/database_threads_search.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

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

static int send_success(TEAMS_A, thread_t *thread)
{
    int len = strlen(thread->uuid) + strlen(THIS_CLIENT.user->uuid) + 45 +
    strlen(thread->title) + strlen(thread->body) + 32;
    char *buff = calloc(sizeof(char), len);

    snprintf(buff, len , "[\"%s\" \"%s\" \"%ld\" \"%s\" \"%s\"]",
    thread->uuid, THIS_CLIENT.user->uuid, thread->timestamp,
    thread->title, thread->body);
    printf("%s\n", buff);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (TEAMS_CLIENTS[i].socket == 0 || !TEAMS_CLIENTS[i].user)
            continue;
        if (i == param->id)
            client_reply(param->clients, i, CREATE_THREAD, buff);
        else
            client_reply(param->clients, i, GET_THREAD, buff);
    }
    free(buff);
    return (CREATE_THREAD);
}

static bool thread_already_exists(TEAMS_A)
{
    database_t *found = db_multiple_search_threads_by_title(THIS_DB,
    THIS_ARG[1]);
    bool retval = false;

    if (db_search_thread_by_channel_id(found, THIS_CLIENT.team->id))
        retval = true;
    free(found->channels);
    free(found->discussions);
    free(found->users_teams);
    free(found->users);
    free(found->threads);
    free(found->messages);
    free(found->teams);
    return retval;
}

static int send_already_exists(TEAMS_A)
{
    int len = strlen(THIS_ARG[1]) + strlen(THIS_ARG[2]) + 13;
    char *buff = calloc(sizeof(char), len);
    int retval = -1;

    snprintf(buff, len, "[ \"%s\" \"%s\"]", THIS_ARG[1], THIS_ARG[2]);
    printf("%s\n", buff);
    retval = client_reply(PARAM_CID, RESOURCE_ALREADY_EXISTS, buff);
    free(buff);
    return retval;
}

int command_create_thread(TEAMS_A)
{
    thread_t *thread = 0;

    if (param->arg.nb < 3) {
        return client_reply(param->clients, param->id, MISSING_PARAMETER, "");
    } else if (param->arg.nb > 3)
        return client_reply(param->clients, param->id, INVALID_FORMAT, "");
    if (!is_in_team(param))
        return client_reply(PARAM_CID, FORBIDDEN, EMPTY_REPLY);
    if (thread_already_exists(param))
        return send_already_exists(param);
    thread = thread_init(param->arg.array[1], param->arg.array[2],
    THIS_CLIENT.channel->id);
    db_add_thread(THIS_DB, thread);
    server_event_thread_created(THIS_CLIENT.channel->uuid, thread->uuid,
    THIS_CLIENT.user->uuid, thread->title, thread->body);
    return send_success(param, thread);
}
