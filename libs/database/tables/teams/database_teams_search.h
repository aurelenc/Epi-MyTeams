/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** database_teams_search
*/

#pragma once

#include "database.h"
#include "team.h"
#include "team_search.h"

///
/// @brief It searches the database for a team with the given id
///
/// @param db The database to search in.
/// @param id The id of the team to search for.
///
/// @return A pointer to a team_t struct.
///
static inline team_t *db_search_team_by_id(database_t *db, const id_t id)
{
    return (team_t *)llist_search(db->teams, &team_id_compare, &id);
};

///
/// @brief It searches the database for a team with the given uuid
///
/// @param db The database to search in.
/// @param uuid The uuid of the team to search for.
///
/// @return A pointer to a team_t struct.
///
static inline team_t *db_search_team_by_uuid(database_t *db, const char *uuid)
{
    return (team_t *)llist_search(db->teams, &team_uuid_compare, uuid);
};
