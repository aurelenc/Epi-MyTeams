/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** database_messages_deletion
*/

#pragma once

#include "message.h"
#include "database.h"
#include "message_search.h"

///
/// @brief It deletes a message from the database by its id
///
/// @param db The database to delete the message from.
/// @param id The id of the message to delete.
///
/// @return A boolean value.
///
static inline bool db_delete_msg_by_id(database_t *db, const id_t id)
{
    return llist_delif(db->messages, &msg_id_compare, &id);
}

///
/// @brief It deletes a message from the database by its uuid
///
/// @param db The database to delete the message from.
/// @param uuid The uuid of the message to delete.
///
/// @return A boolean value.
///
static inline bool db_delete_msg_by_uuid(database_t *db, const char *uuid)
{
    return llist_delif(db->messages, &msg_uuid_compare, uuid);
}
