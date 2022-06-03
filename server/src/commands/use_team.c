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

int command_use_team(TEAMS_A)
{
    team_t *team = 0;
    id_pair_t pair;
    id_pair_t *search = 0;

    if (!THIS_CLIENT.user)
        return client_reply(PARAM_CID, FORBIDDEN, EMPTY_REPLY);
    if (param->arg.nb < 2)
        return client_reply(PARAM_CID, MISSING_PARAMETER, EMPTY_REPLY);
    team = db_search_team_by_uuid(THIS_DB, THIS_ARG[1]);
    if (!team)
        return client_reply(PARAM_CID, NOT_FOUND, EMPTY_REPLY);
    pair.team_id = team->id;
    pair.user_id = THIS_CLIENT.user->id;
    search = db_search_user_team_by_pair(THIS_DB, &pair);
    if (!search)
        return client_reply(PARAM_CID, FORBIDDEN, EMPTY_REPLY);
    THIS_CLIENT.team = team;
    THIS_CLIENT.channel = 0;
    THIS_CLIENT.thread = 0;
    return client_reply(PARAM_CID, SUCCESS, EMPTY_REPLY);
}
