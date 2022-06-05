/*
** EPITECH PROJECT, 2022
** Epi-MyTeams
** File description:
** unsubscribe
*/

#include "reply_codes.h"
#include "server.h"
#include "tables/users_x_teams/database_users_x_teams_deletion.h"
#include "tables/teams/database_teams_search.h"
#include "tables/users/database_users_search.h"
#include "logging_server.h"
#include <stdio.h>

static int send_reply_unknow(TEAMS_A)
{
    char team_id_formatted[(UUID_SIZE * 2) + 10] = {0};

    snprintf(team_id_formatted, (UUID_SIZE * 2) + 9, "[ \"%s\"]",
    THIS_ARG[1]);
    return client_reply(PARAM_CID, UNKNOWN_TEAM, team_id_formatted);
}

static void reset_user_location(TEAMS_A)
{
    THIS_CLIENT.team = 0;
    THIS_CLIENT.channel = 0;
    THIS_CLIENT.thread = 0;
}

static int send_reply_team(TEAMS_A, team_t *team)
{
    char user_id_formatted[(UUID_SIZE * 2) + 10] = {0};

    snprintf(user_id_formatted, (UUID_SIZE * 2) + 9, "[ \"%s\" \"%s\"]",
    THIS_CLIENT.user->uuid, team->uuid);
    server_event_user_unsubscribed(team->uuid, THIS_CLIENT.user->uuid);
    reset_user_location(param);
    return client_reply(PARAM_CID, SUCCESS, user_id_formatted);
}

int command_unsubscribe(TEAMS_A)
{
    id_pair_t pair = {0};
    team_t *team = 0;

    if (!THIS_CLIENT.user)
        return client_reply(PARAM_CID, FORBIDDEN, EMPTY_REPLY);
    if (param->arg.nb < 2)
        return client_reply(PARAM_CID, MISSING_PARAMETER, EMPTY_REPLY);
    team = db_search_team_by_uuid(THIS_DB, THIS_ARG[1]);
    if (!team) {
        return send_reply_unknow(param);
    }
    pair.user_id = THIS_CLIENT.user->id;
    pair.team_id = team->id;
    if (db_delete_user_team_by_pair(THIS_DB, &pair) == true) {
        return send_reply_team(param, team);
    }
    return client_reply(PARAM_CID, FORBIDDEN, EMPTY_REPLY);
}
