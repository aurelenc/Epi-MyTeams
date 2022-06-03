/*
** EPITECH PROJECT, 2022
** Epi-MyTeams
** File description:
** use_team
*/

#include "reply_codes.h"
#include "server.h"
#include "tables/teams/database_teams_search.h"
#include "tables/users_x_teams/database_users_x_teams_multiple_search.h"
#include "tables/users/user_search.h"
#include "tables/users_x_teams/database_users_x_teams_search.h"
#include "tables/users/database_users_search.h"
#include <string.h>

int command_use_team(command_param_t *param)
{
    team_t *team = 0;
    id_pair_t pair;
    id_pair_t *search = 0;

    if (param->arg.nb < 2)
        return client_reply(param->clients, param->id, MISSING_PARAMETER);
    team = db_search_team_by_uuid(param->srv->db, param->arg.array[1]);
    if (!team)
        return client_reply(PARAM_CID, NOT_FOUND);
    pair.team_id = team->id;
    pair.user_id = db_search_user_by_uuid(param->srv->db, THIS_CLIENT.user)->id;
    search = db_search_user_team_by_pair(param->srv->db, &pair);
    if (!search)
        return client_reply(PARAM_CID, FORBIDDEN);
    return client_reply_success(PARAM_CID, "");
}
