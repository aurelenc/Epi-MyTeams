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
/// @brief It deletes a thread from the database if it has the same start
/// message id as the one passed in
///
/// @param db The database to delete the thread from.
/// @param start_msg_id The id of the start message to delete the thread of.
///
/// @return A boolean value.
///
static inline bool db_delete_thread_by_start_msg_id(database_t *db,
const id_t start_msg_id)
{
    return llist_delif(db->threads, &thread_start_msg_id_compare,
    &start_msg_id);
};
