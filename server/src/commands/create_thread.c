/*
** EPITECH PROJECT, 2022
** Epi-MyTeams
** File description:
** create_thread
*/

#include "logging_server.h"
#include "reply_codes.h"
#include "server.h"
#include "tables/teams/database_teams_search.h"
#include "tables/users_x_teams/database_users_x_teams_search.h"
#include "tables/threads/database_threads_add.h"
#include "tables/channels/database_channels_search.h"
#include "tables/users/database_users_search.h"

static bool is_in_team(command_param_t *param)
{
    team_t *team = 0;
    id_pair_t pair;
    id_pair_t *search = 0;

    team = db_search_team_by_id(param->srv->db, THIS_CLIENT.team_id);
    if (!team)
        return false;
    pair.team_id = team->id;
    pair.user_id = THIS_CLIENT.user;
    search = db_search_user_team_by_pair(param->srv->db, &pair);
    if (!search)
        return false;
    return true;
}

int command_create_thread(command_param_t *param)
{
    thread_t *thread = 0;

    if (param->arg.nb < 3) {
        return client_reply(param->clients, param->id, MISSING_PARAMETER);
    } else if (param->arg.nb > 3) {
        return client_reply(param->clients, param->id, INVALID_FORMAT);
    }
    if (!is_in_team(param))
        return client_reply(PARAM_CID, FORBIDDEN);
    thread = thread_init(llist_get_size(SRV_DB->threads) + 1,
    param->arg.array[1], param->arg.array[2], THIS_CLIENT.channel_id);
    db_add_thread(SRV_DB, thread);
    server_event_thread_created(db_search_channel_by_id(SRV_DB,
    THIS_CLIENT.channel_id)->uuid, thread->uuid, db_search_user_by_id(SRV_DB,
    THIS_CLIENT.user)->uuid, thread->title, thread->body);
    return client_reply_success(param->clients, param->id, success_buff);//
}
