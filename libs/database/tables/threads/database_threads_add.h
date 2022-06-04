/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** database_thread
*/

#pragma once

#include "thread.h"
#include "database.h"

///
/// @brief It adds a thread to the database
///
/// @param db The database object
/// @param thread The thread to add to the database.
///
/// @return A boolean value.
///
static inline bool db_add_thread(database_t *db, thread_t *thread)
{
    if (!thread->id)
        thread->id = llist_get_size(db->threads) + 1;
    return llist_append(db->threads, thread);
}
