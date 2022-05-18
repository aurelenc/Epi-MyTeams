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
/// @brief It deletes a message from the database if it has the same user id as
/// the one passed in
///
/// @param db The database to delete the message from.
/// @param user_id The id of the user to delete the message of.
///
/// @return A boolean value.
///
static inline bool db_delete_msg_by_user_id(database_t *db,
const id_t user_id)
{
    return llist_delif(db->messages, &msg_user_id_compare, &user_id);
};

///
/// @brief It deletes a message from the database if it has the same thread id
/// as the one passed in
///
/// @param db The database to delete the message from.
/// @param thread_id The id of the thread to delete the message of.
///
/// @return A boolean value.
///
static inline bool db_delete_msg_by_thread_id(database_t *db,
const id_t thread_id)
{
    return llist_delif(db->messages, &msg_thread_id_compare, &thread_id);
};

///
/// @brief It deletes a message from the database if it has the same channel id
// as the one passed in
///
/// @param db The database to delete the message from.
/// @param channel_id The id of the channel to delete the message of.
///
/// @return A boolean value.
///
static inline bool db_delete_msg_by_channel_id(database_t *db,
const id_t channel_id)
{
    return llist_delif(db->messages, &msg_channel_id_compare, &channel_id);
};

///
/// @brief It deletes a message from the database if it has the same discussion
/// id as the one passed in
///
/// @param db The database to delete the message from.
/// @param discu_id The id of the discussion to delete the message of.
///
/// @return A boolean value.
///
static inline bool db_delete_msg_by_discussion_id(database_t *db,
const id_t discu_id)
{
    return llist_delif(db->messages, &msg_discussion_id_compare, &discu_id);
};
