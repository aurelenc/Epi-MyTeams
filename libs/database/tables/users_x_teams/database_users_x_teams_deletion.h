/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** database_users_x_teams_deletion
*/

#pragma once

#include "users_x_teams.h"
#include "database.h"
#include "user_team_search.h"

///
/// @brief It deletes the first user-team associations for a given user
///
/// @param db The database object
/// @param id The id of the user to delete the team from.
///
/// @return A boolean value.
///
static inline bool db_delete_user_team_by_user_id(
database_t *db, const id_t id)
{
    return llist_delif(db->users_teams, &user_team_user_id_compare, &id);
};

///
/// @brief It deletes the first user-team associations that have the given team
/// id
///
/// @param db The database object
/// @param id The id of the team to delete.
///
/// @return A boolean value.
///
static inline bool db_delete_user_team_by_team_id(
database_t *db, const id_t id)
{
    return llist_delif(db->users_teams, &user_team_team_id_compare, &id);
};

///
/// @brief It deletes a user-team pair from the database
///
/// @param db The database to delete from.
/// @param pair The pair of user and team IDs to delete.
///
/// @return A boolean value.
///
static inline bool db_delete_user_team_by_pair(database_t *db,
const id_pair_t *pair)
{
    return llist_delif(db->users_teams, &user_team_pair_compare, pair);
};
