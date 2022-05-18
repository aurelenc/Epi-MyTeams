/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** database_users_x_teams
*/

#pragma once

#include "users_x_teams.h"
#include "database.h"

///
/// @brief It adds a user-team relation to the database
///
/// @param db The database object
/// @param pair A pointer to an id_pair_t struct.
///
/// @return A boolean value.
///
static inline bool db_add_user_team_relation(database_t *db, id_pair_t *pair)
{
    return llist_append(db->users_teams, pair);
};
