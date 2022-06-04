/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** database_messages_search_relation
*/

#pragma once

#include "message.h"
#include "database.h"
#include "message_search.h"

///
/// @brief It searches the database's
/// message list for a message with the given user ID
///
/// @param db The database to search in.
/// @param user_id The user ID to search for.
///
/// @return A pointer to a msg_t struct.
///
static inline msg_t *db_search_msg_by_user_id(database_t *db,
const id_t user_id)
{
    return ((msg_t *)llist_search(db->messages, &msg_user_id_compare, &user_id));
}

///
/// @brief It searches the database's
/// message list for a message with the given thread ID
///
/// @param db The database to search in.
/// @param thread_id The thread ID to search for.
///
/// @return A pointer to a msg_t struct.
///
static inline msg_t *db_search_msg_by_thread_id(database_t *db,
const id_t thread_id)
{
    return ((msg_t *)llist_search(db->messages, &msg_thread_id_compare,
    &thread_id));
}

///
/// @brief It searches the database's
/// message list for a message with the given discussion ID
///
/// @param db The database to search in.
/// @param discu_id The discussion ID to search for.
///
/// @return A pointer to a msg_t struct.
///
static inline msg_t *db_search_msg_by_discussion_id(database_t *db,
const id_t discu_id)
{
    return ((msg_t *)llist_search(db->messages, &msg_discussion_id_compare,
    &discu_id));
}
