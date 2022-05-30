/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** database_users_add
*/

#pragma once

#include "database.h"
#include "user.h"

///
/// @brief Add a user to the database.
///
/// @param db The database to add the user to.
/// @param user The user to add to the database.
///
/// @return A boolean value.
///
static inline bool db_add_user(database_t *db, user_t *user)
{
    return llist_append(db->users, user);
};
