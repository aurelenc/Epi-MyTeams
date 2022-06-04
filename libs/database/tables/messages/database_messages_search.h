/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** database_messages_search
*/

#pragma once

#include "message.h"
#include "database.h"
#include "message_search.h"

///
/// @brief It searches the database for a message with the given id
///
/// @param db The database to search in.
/// @param id The id of the message to search for.
///
/// @return A pointer to a msg_t struct.
///
static inline msg_t *db_search_msg_by_id(database_t *db, const id_t id)
{
    return ((msg_t *)llist_search(db->messages, &msg_id_compare, &id));
}

///
/// @brief It searches the database for a message with the given uuid
///
/// @param db The database to search in.
/// @param uuid The uuid of the message to search for.
///
/// @return A pointer to a msg_t struct.
///
static inline msg_t *db_search_msg_by_uuid(database_t *db, const char *uuid)
{
    return ((msg_t *)llist_search(db->messages, &msg_uuid_compare, uuid));
}
