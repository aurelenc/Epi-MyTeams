/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** database_users_x_teams_multiple_search
*/

#include "database.h"
#include "database_management.h"
#include "users_x_teams.h"
#include "user_team_search.h"
#include "tables/users/user_search.h"
#include "tables/teams/team_search.h"
#include <stdlib.h>

database_t *db_search_users_of_a_team_by_its_id(database_t *db,
const id_t id)
{
    database_t *found = db_creation();
    id_t *users_id;

    if (!found)
        return (0);
    llist_destruction(found->users_teams);
    llist_destruction(found->users);
    found->users_teams = llist_multiple_search(db->users_teams,
    &user_team_team_id_compare, &id);
    users_id = calloc(sizeof(id_t), llist_get_size(found->users_teams) + 1);
    if (!users_id)
        return (0);
    for (int i = 0; i < llist_get_size(found->users_teams); i++) {
        users_id[i] =
        ((id_pair_t *)llist_get(found->users_teams, i))->user_id;
    }
    users_id[llist_get_size(found->users_teams)] = 0;
    found->users = llist_multiple_search(db->users, user_id_array_compare,
    users_id);
    return found;
}

database_t *db_search_teams_of_an_user_by_his_id(database_t *db,
const id_t id)
{
    database_t *found = db_creation();
    id_t *teams_id;

    if (!found)
        return (0);
    llist_destruction(found->users_teams);
    llist_destruction(found->teams);
    found->users_teams = llist_multiple_search(db->users_teams,
    &user_team_user_id_compare, &id);
    teams_id = calloc(sizeof(id_t), llist_get_size(found->users_teams) + 1);
    if (!teams_id)
        return (0);
    for (int i = 0; i < llist_get_size(found->users_teams); i++) {
        teams_id[i] =
        ((id_pair_t *)llist_get(found->users_teams, i))->team_id;
    }
    teams_id[llist_get_size(found->users_teams)] = 0;
    found->teams = llist_multiple_search(db->teams, team_id_array_compare,
    teams_id);
    return found;
}
