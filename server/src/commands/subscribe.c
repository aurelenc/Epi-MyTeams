/*
** EPITECH PROJECT, 2022
** Epi-MyTeams
** File description:
** subscribe
*/

#include "reply_codes.h"
#include "server.h"
#include "tables/users_x_teams/database_users_x_teams_add.h"
#include "tables/teams/database_teams_search.h"
#include "tables/users/database_users_search.h"
#include "logging_server.h"

int command_subscribe(command_param_t *param)
{
    id_pair_t pair = {0};
    team_t *team = 0;

    if (!THIS_CLIENT.user)
        return client_reply(PARAM_CID, FORBIDDEN);
    if (param->arg.nb < 2)
        return client_reply(PARAM_CID, MISSING_PARAMETER);
    team = db_search_team_by_uuid(param->srv->db, param->arg.array[1]);
    if (!team)
        return client_reply(PARAM_CID, NOT_FOUND);
    pair.user_id = THIS_CLIENT.user->id;
    pair.team_id = team->id;
    if (db_add_user_team_relation(param->srv->db, &pair) == true) {
        server_event_user_subscribed(team->uuid, THIS_CLIENT.user->uuid);
        return client_reply_success(PARAM_CID, "");
    }
    return client_reply(PARAM_CID, FORBIDDEN);
}
