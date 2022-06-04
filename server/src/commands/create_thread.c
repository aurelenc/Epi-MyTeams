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

static char *get_success(TEAMS_A, thread_t *thread)
{
    int len = strlen(thread->uuid) + strlen(THIS_CLIENT.user->uuid) + 45 +
    strlen(thread->title) + strlen(thread->body) + 32;
    char *buff = calloc(sizeof(char), len);

    snprintf(buff, len , "[\"%s\" \"%s\" \"%ld\" \"%s\" \"%s\"]\n",
    thread->uuid, THIS_CLIENT.user->uuid, thread->timestamp,
    thread->title, thread->body);
    printf("%s\n", buff);
    return (buff);
}

int command_create_thread(TEAMS_A)
{
    thread_t *thread = 0;
    char *success_buff = 0;

    if (param->arg.nb < 3) {
        return client_reply(param->clients, param->id, MISSING_PARAMETER, "");
    } else if (param->arg.nb > 3) {
        return client_reply(param->clients, param->id, INVALID_FORMAT, "");
    }
    if (!is_in_team(param))
        return client_reply(PARAM_CID, FORBIDDEN, EMPTY_REPLY);
    thread = thread_init(param->arg.array[1], param->arg.array[2],
    THIS_CLIENT.channel->id);
    db_add_thread(THIS_DB, thread);
    server_event_thread_created(THIS_CLIENT.channel->uuid, thread->uuid,
    THIS_CLIENT.user->uuid, thread->title, thread->body);
    success_buff = get_success(param, thread);
    client_reply(param->clients, param->id, CREATE_THREAD, success_buff);
    free(success_buff);
    return CREATE_THREAD;
}
