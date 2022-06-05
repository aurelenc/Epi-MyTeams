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
#include <stdio.h>

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

static int do_channel_actions(TEAMS_A, team_t * team, channel_t *channel)
{
    thread_t *thread = db_search_thread_by_uuid(THIS_DB, THIS_ARG[3]);
    char team_uuid_format[UUID_SIZE + 10] = {0};

    if (thread && thread->channel_id == channel->id) {
        THIS_CLIENT.team = team;
        THIS_CLIENT.channel = channel;
        THIS_CLIENT.thread = thread;
        return client_reply(PARAM_CID, SUCCESS, EMPTY_REPLY);
    }
    snprintf(team_uuid_format, UUID_SIZE + 9, "[ \"%s\"]", THIS_ARG[3]);
    return client_reply(PARAM_CID, UNKNOWN_THREAD, team_uuid_format);
}

static int do_team_actions(TEAMS_A, team_t *team)
{
    channel_t *channel = 0;
    char team_uuid_format[UUID_SIZE + 10] = {0};

    if (!is_cli_in_team(THIS_DB, &THIS_CLIENT, team)) {
        return client_reply(PARAM_CID, FORBIDDEN, EMPTY_REPLY);
    }
    channel = db_search_channel_by_uuid(THIS_DB, THIS_ARG[2]);
    if (channel && channel->team_id == team->id) {
        return do_channel_actions(param, team, channel);
    }
    snprintf(team_uuid_format, UUID_SIZE + 9, "[ \"%s\"]", THIS_ARG[2]);
    return client_reply(PARAM_CID, UNKNOWN_CHANNEL, team_uuid_format);
}

int command_use_three_arg(TEAMS_A)
{
    team_t *team = db_search_team_by_uuid(THIS_DB, THIS_ARG[1]);
    char team_uuid_format[UUID_SIZE + 10] = {0};

    if (team) {
        return do_team_actions(param, team);
    }
    snprintf(team_uuid_format, UUID_SIZE + 9, "[ \"%s\"]", THIS_ARG[1]);
    return client_reply(PARAM_CID, UNKNOWN_TEAM, team_uuid_format);
}
