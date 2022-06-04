/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** database_threads_deletion
*/

#pragma once

#include "thread.h"
#include "database.h"
#include "thread_search.h"

///
/// @brief It deletes a thread from the database by its id
///
/// @param db The database to delete the thread from.
/// @param id The id of the thread to delete.
///
/// @return A boolean value.
///
static inline bool db_delete_thread_by_id(database_t *db, const id_t id)
{
    return llist_delif(db->threads, &thread_id_compare, &id);
}

///
/// @brief It deletes a thread from the database by its uuid
///
/// @param db The database to delete the thread from.
/// @param uuid The uuid of the thread to delete.
///
/// @return A boolean value.
///
static inline bool db_delete_thread_by_uuid(database_t *db, const char *uuid)
{
    return llist_delif(db->threads, &thread_uuid_compare, uuid);
}

///
/// @brief It deletes a thread from the database if it has the same start
/// message id as the one passed in
///
/// @param db The database to delete the thread from.
/// @param channel_id The id of the start message to delete the thread of.
///
/// @return A boolean value.
///
static inline bool db_delete_thread_by_channel_id(database_t *db,
const id_t channel_id)
{
    return llist_delif(db->threads, &thread_channel_id_compare,
    &channel_id);
}
