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
/// @brief It searches the database's
///thread list for a thread with the given start message ID
///
/// @param db The database to search in.
/// @param start_msg_id The start message ID to search for.
///
/// @return A pointer to a thread_t struct.
///
static inline thread_t *db_search_thread_by_start_msg_id(database_t *db,
const id_t start_msg_id)
{
    return (thread_t *)llist_search(db->threads, &thread_start_msg_id_compare,
    &start_msg_id);
};
