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

int command_use_thread(command_param_t *param)
{
    thread_t *thread = 0;

    if (param->arg.nb < 2)
        return client_reply(param->clients, param->id, MISSING_PARAMETER);
    thread = db_search_thread_by_uuid(param->srv->db, param->arg.array[1]);
    if (!thread)
        return client_reply(PARAM_CID, NOT_FOUND);
    if (thread->channel_id == THIS_CLIENT.channel_id) {
        THIS_CLIENT.thread_id = thread->id;
        THIS_CLIENT.thread_id = 0;
        return client_reply_success(PARAM_CID, "");
    }
    return client_reply(PARAM_CID, FORBIDDEN);
}
