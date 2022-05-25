/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** database_teams_deletion
*/

#pragma once

#include "database.h"
#include "team.h"
#include "team_search.h"

///
/// @brief It deletes a team from the database by its id
///
/// @param db The database to delete the team from.
/// @param id The id of the team to delete
///
/// @return A boolean value.
///
static inline bool db_delete_team_by_id(database_t *db, const id_t id)
{
    return llist_delif(db->teams, &team_id_compare, &id);
}

///
/// @brief It deletes the first team in the database whose uuid matches the
/// given uuid
///
/// @param db The database to search in.
/// @param uuid The uuid of the team to search for.
///
/// @return A boolean value.
///
static inline bool db_delete_team_by_uuid(database_t *db, const char *uuid)
{
    return llist_delif(db->teams, &team_uuid_compare, uuid);
}

///
/// @brief It deletes the first team in the database whose name matches the
/// given name
///
/// @param db The database to search in.
/// @param name The name of the team to search for.
///
/// @return A boolean value.
///
static inline bool db_delete_team_by_name(database_t *db, const char *name)
{
    return llist_delif(db->teams, &team_name_compare, name);
}
