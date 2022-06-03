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

static void reset_user_location(TEAMS_A)
{
    THIS_CLIENT.team = 0;
    THIS_CLIENT.channel = 0;
    THIS_CLIENT.thread = 0;
}

int command_unsubscribe(TEAMS_A)
{
    id_pair_t pair = {0};
    team_t *team = 0;

    if (!THIS_CLIENT.user)
        return client_reply(PARAM_CID, FORBIDDEN);
    if (param->arg.nb < 2)
        return client_reply(PARAM_CID, MISSING_PARAMETER);
    team = db_search_team_by_uuid(THIS_DB, THIS_ARG[1]);
    if (!team)
        return client_reply(PARAM_CID, NOT_FOUND);
    pair.user_id = THIS_CLIENT.user->id;
    pair.team_id = team->id;
    if (db_delete_user_team_by_pair(THIS_DB, &pair) == true) {
        server_event_user_unsubscribed(team->uuid, THIS_CLIENT.user->uuid);
        reset_user_location(param);
        return client_reply_success(PARAM_CID, "");
    }
    return client_reply(PARAM_CID, FORBIDDEN);
}
