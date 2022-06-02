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
#include <string.h>

int command_use_team(command_param_t *param)
{
    team_t *team = 0;
    database_t *new = 0;
    node_t *iterator = 0;

    if (param->arg.nb < 2)
        return client_reply(param->clients, param->id, MISSING_PARAMETER);
    team = db_search_team_by_uuid(param->srv->db, param->arg.array[1]);
    if (!team)
        return client_reply(PARAM_CID, NOT_FOUND);
    new = db_search_users_of_a_team_by_its_id(param->srv->db, team->id);
    iterator = new->users->first;
    while (iterator) {
        if (user_uuid_compare(iterator->data, param->clients[param->id].user)) {
            memset(THIS_CLIENT.team, 0, UUID_SIZE);
            strcpy(THIS_CLIENT.team, team->uuid);
            return client_reply_success(PARAM_CID, "");
        }
        iterator = iterator->next;
    }
    return client_reply(PARAM_CID, FORBIDDEN);
}
