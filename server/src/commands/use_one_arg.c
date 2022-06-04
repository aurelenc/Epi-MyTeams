/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** use_one_arg
*/

#include "reply_codes.h"
#include "server.h"
#include "tables/teams/database_teams_search.h"
#include "tables/threads/database_threads_search.h"
#include "tables/channels/database_channels_search.h"
#include "tables/users_x_teams/database_users_x_teams_search.h"

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

static int do_thread_actions(TEAMS_A, thread_t *thread)
{
    if (THIS_CLIENT.team && THIS_CLIENT.channel
    && THIS_CLIENT.channel->id == thread->channel_id) {
        THIS_CLIENT.thread = thread;
        return client_reply(PARAM_CID, SUCCESS, EMPTY_REPLY);
    }
    return client_reply(PARAM_CID, FORBIDDEN, EMPTY_REPLY);
}

static int do_channel_actions(TEAMS_A, channel_t *channel)
{
    if (THIS_CLIENT.team && THIS_CLIENT.team->id == channel->team_id) {
        THIS_CLIENT.channel = channel;
        THIS_CLIENT.thread = 0;
        return client_reply(PARAM_CID, SUCCESS, EMPTY_REPLY);
    }
    return client_reply(PARAM_CID, FORBIDDEN, EMPTY_REPLY);
}

static int do_team_actions(TEAMS_A, team_t *team)
{
    if (is_cli_in_team(THIS_DB, &THIS_CLIENT, team)) {
        THIS_CLIENT.team = team;
        THIS_CLIENT.channel = 0;
        THIS_CLIENT.thread = 0;
        return client_reply(PARAM_CID, SUCCESS, EMPTY_REPLY);
    }
    return client_reply(PARAM_CID, FORBIDDEN, EMPTY_REPLY);
}

int command_use_one_arg(TEAMS_A)
{
    team_t *team = db_search_team_by_uuid(THIS_DB, THIS_ARG[1]);
    channel_t *channel = 0;
    thread_t *thread = 0;

    if (team) {
        return do_team_actions(param, team);
    }
    channel = db_search_channel_by_uuid(THIS_DB, THIS_ARG[1]);
    if (channel) {
        return do_channel_actions(param, channel);
    }
    thread = db_search_thread_by_uuid(THIS_DB, THIS_ARG[1]);
    if (thread) {
        return do_thread_actions(param, thread);
    }
    return client_reply(PARAM_CID, FORBIDDEN, EMPTY_REPLY);
}
