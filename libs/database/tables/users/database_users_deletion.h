/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** database_users_deletion
*/

#pragma once

#include "database.h"
#include "user.h"
#include "user_search.h"

///
/// @brief It deletes a user, with the given id, in the database
///
/// @param db The database to search in.
/// @param id The id of the user to delete.
///
/// @return A boolean value.
///
static inline bool db_delete_user_by_id(database_t *db, const id_t id)
{
    return llist_delif(db->users, &user_id_compare, &id);
}

///
/// @brief It deletes a user, with the given uuid, in the database
///
/// @param db the database.
/// @param uuid the uuid of the user to delete.
///
/// @return A boolean value.
///
static inline bool db_delete_user_by_uuid(database_t *db,
const char *uuid)
{
    return llist_delif(db->users, &user_uuid_compare, uuid);
}

///
/// @brief It deletes a user, with the given pseudo, in the database
///
/// @param db the database.
/// @param pseudo the pseudo of the user to delete.
///
/// @return A boolean value.
///
static inline bool db_delete_user_by_pseudo(database_t *db,
const char *pseudo)
{
    return llist_delif(db->users, &user_pseudo_compare, pseudo);
}
