/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** database_messages_multiple_search_relation
*/

#pragma once

#include "message.h"
#include "database.h"
#include "database_management.h"
#include "message_search.h"

///
/// @brief It searches the database for messages that have the same user id as the one
/// passed as a parameter
///
/// @param db the database to search in
/// @param user_id The user id to search for.
///
/// @return A pointer to an allocated database_t structure
///
static inline database_t *db_multiple_search_msg_by_user_id(database_t *db,
const id_t user_id)
{
    database_t *found = db_creation();

    if (!found)
        return (0);
    found->messages = llist_multiple_search(db->messages, &msg_user_id_compare, &user_id);
    return found;
};

///
/// @brief It searches for messages in a database  that have the same user id as the one passed as a parameter
///
/// @param db the database to search in
/// @param thread_id The thread id to search for.
///
/// @return A pointer to an allocated database_t structure
///
static inline database_t *db_multiple_search_msg_by_thread_id(database_t *db,
const id_t thread_id)
{
    database_t *found = db_creation();

    if (!found)
        return (0);
    found->messages = llist_multiple_search(db->messages, &msg_thread_id_compare,
    &thread_id);
    return (found);
};

///
/// @brief It searches for messages in the database that have the same channel id as the one passed as argument
///
/// @param db the database to search in
/// @param channel_id The id of the channel to search for.
///
/// @return A pointer to an allocated database_t structure
///
static inline database_t *db_multiple_search_msg_by_channel_id(database_t *db,
const id_t channel_id)
{
    database_t *found = db_creation();

    if (!found)
        return (0);
    found->messages = llist_multiple_search(db->messages, &msg_channel_id_compare,
    &channel_id);
    return (found);
};

///
/// @brief It searches for messages in the database that have the same discussion id as the one passed as argument
///
/// @param db the database to search in
/// @param discu_id the id of the discussion you want to search for
///
/// @return A pointer to an allocated database_t structure
///
static inline database_t *db_multiple_search_msg_by_discussion_id(database_t *db,
const id_t discu_id)
{
    database_t *found = db_creation();

    if (!found)
        return (0);
    found->messages = llist_multiple_search(db->messages, &msg_discussion_id_compare,
    &discu_id);
    return (found);
};
