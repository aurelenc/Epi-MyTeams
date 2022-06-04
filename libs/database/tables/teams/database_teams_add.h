/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** database_teams_add
*/

#pragma once

#include "database.h"
#include "team.h"

///
/// @brief It adds a team to the database
///
/// @param db The database to add the team to.
/// @param team The team to add to the database.
///
/// @return A boolean value.
///
static inline bool db_add_team(database_t *db, team_t *team)
{
    if (!team->id)
        team->id = llist_get_size(db->teams) + 1;
    return llist_append(db->teams, team);
}
