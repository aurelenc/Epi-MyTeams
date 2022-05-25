/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** database_threads_search
*/

#pragma once

#include "thread.h"
#include "database.h"
#include "thread_search.h"

///
/// @brief It searches the database for a thread with the given id
///
/// @param db The database to search in.
/// @param id The id of the thread to search for.
///
/// @return A pointer to a thread_t struct.
///
static inline thread_t *db_search_thread_by_id(database_t *db, const id_t id)
{
    return (thread_t *)llist_search(db->threads, &thread_id_compare, &id);
};

///
/// @brief It searches the database for a thread with the given uuid
///
/// @param db The database to search in.
/// @param uuid The uuid of the thread to search for.
///
/// @return A pointer to a thread_t struct.
///
static inline thread_t *db_search_thread_by_uuid(database_t *db, const char *uuid)
{
    return (thread_t *)llist_search(db->threads, &thread_uuid_compare, uuid);
};

///
/// @brief It searches the database's
///thread list for a thread with the given start message ID
///
/// @param db The database to search in.
/// @param channel_id The start message ID to search for.
///
/// @return A pointer to a thread_t struct.
///
static inline thread_t *db_search_thread_by_channel_id(database_t *db,
const id_t channel_id)
{
    return (thread_t *)llist_search(db->threads, &thread_channel_id_compare,
    &channel_id);
};
