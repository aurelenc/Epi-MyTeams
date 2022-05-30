/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** database_messages_add
*/

#pragma once

#include "message.h"
#include "database.h"

///
/// @brief It adds a message to the database
///
/// @param db The database object
/// @param message The message to add to the database.
///
/// @return A boolean value.
///
static inline bool db_add_msg(database_t *db, msg_t *message)
{
    return llist_append(db->messages, message);
};
