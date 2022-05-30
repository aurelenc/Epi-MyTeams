/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** database_users_x_teams_search
*/

#pragma once

#include "users_x_teams.h"
#include "database.h"
#include "user_team_search.h"

///
/// @brief It searches the user-team pair whose user ID matches the given ID
///
/// @param db The database to search in.
/// @param id The user id to search for.
///
/// @return A pointer to an id_pair_t struct.
///
static inline id_pair_t *db_search_user_team_by_user_id(database_t *db,
const id_t id)
{
    return (id_pair_t *)llist_search(db->users_teams,
    &user_team_user_id_compare, &id);
};

///
/// @brief It searches the user-team pair whose team ID matches the given ID
///
/// @param db The database to search in.
/// @param id The id of the team to search for.
///
/// @return A pointer to an id_pair_t struct.
///
static inline id_pair_t *db_search_user_team_by_team_id(database_t *db,
const id_t id)
{
    return (id_pair_t *)llist_search(db->users_teams,
    &user_team_team_id_compare, &id);
};

///
/// @brief It searches the database for a user-team pair that matches the given
/// user-team pair
///
/// @param db The database to search in.
/// @param id The id of the team to search for.
///
/// @return A pointer to the id_pair_t struct that is found in the linked list.
///
static inline id_pair_t *db_search_user_team_by_pair(database_t *db,
const id_pair_t *id)
{
    return (id_pair_t *)llist_search(db->users_teams,
    &user_team_pair_compare, id);
};
