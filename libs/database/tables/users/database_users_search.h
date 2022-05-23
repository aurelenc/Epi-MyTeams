/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** database_users_search
*/

#pragma once

#include "database.h"
#include "user.h"
#include "user_search.h"

///
/// @brief It searches the database for a user with the given id
///
/// @param db The database to search in.
/// @param id The id of the user to search for.
///
/// @return A pointer to a user_t struct.
///
static inline user_t *db_search_user_by_id(database_t *db, const id_t id)
{
    return (user_t *)llist_search(db->users, &user_id_compare, &id);
};

///
/// @brief It searches the database for a user with the given uuid
///
/// @param db the database
/// @param uuid the uuid of the user to search for
///
/// @return A pointer to the user_t struct.
///
static inline user_t *db_search_user_by_uuid(database_t *db,
const char *uuid)
{
    return (user_t *)llist_search(db->users, &user_uuid_compare, uuid);
};

///
/// @brief It searches the database for a user with the given pseudo
///
/// @param db the database
/// @param pseudo the pseudo of the user to search for
///
/// @return A pointer to the user_t struct.
///
static inline user_t *db_search_user_by_pseudo(database_t *db,
const char *pseudo)
{
    return (user_t *)llist_search(db->users, &user_pseudo_compare, pseudo);
};
