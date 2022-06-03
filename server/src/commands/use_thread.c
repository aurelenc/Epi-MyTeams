/*
** EPITECH PROJECT, 2022
** Epi-MyTeams
** File description:
** use_thread
*/

#include "reply_codes.h"
#include "server.h"
#include "tables/threads/database_threads_search.h"
#include "tables/users/user_search.h"

int command_use_thread(TEAMS_A)
{
    thread_t *thread = 0;

    if (!THIS_CLIENT.user)
        return client_reply(PARAM_CID, FORBIDDEN);
    if (param->arg.nb < 2)
        return client_reply(PARAM_CID, MISSING_PARAMETER);
    thread = db_search_thread_by_uuid(THIS_DB, THIS_ARG[1]);
    if (!thread)
        return client_reply(PARAM_CID, NOT_FOUND);
    if (thread->channel_id == THIS_CLIENT.channel->id) {
        THIS_CLIENT.thread = thread;
        return client_reply_success(PARAM_CID, "");
    }
    return client_reply(PARAM_CID, FORBIDDEN);
}
