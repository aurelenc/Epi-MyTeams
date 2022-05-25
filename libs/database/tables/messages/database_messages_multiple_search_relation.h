/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** database_messages_multiple_search_relation
*/

#pragma once

#include "database.h"

typedef unsigned int id_t;

///
/// @brief It searches the database for messages that have the same user id as the one
/// passed as a parameter
///
/// @param db the database to search in
/// @param user_id The user id to search for.
///
/// @return A pointer to an allocated database_t structure
///
database_t *db_multiple_search_msg_by_user_id(database_t *db,
const id_t user_id);

///
/// @brief It searches for messages in a database  that have the same user id as the one passed as a parameter
///
/// @param db the database to search in
/// @param thread_id The thread id to search for.
///
/// @return A pointer to an allocated database_t structure
///
database_t *db_multiple_search_msg_by_thread_id(database_t *db,
const id_t thread_id);

///
/// @brief It searches for messages in the database that have the same channel id as the one passed as argument
///
/// @param db the database to search in
/// @param channel_id The id of the channel to search for.
///
/// @return A pointer to an allocated database_t structure
///
database_t *db_multiple_search_msg_by_channel_id(database_t *db,
const id_t channel_id);

///
/// @brief It searches for messages in the database that have the same discussion id as the one passed as argument
///
/// @param db the database to search in
/// @param discu_id the id of the discussion you want to search for
///
/// @return A pointer to an allocated database_t structure
///
database_t *db_multiple_search_msg_by_discussion_id(database_t *db,
const id_t discu_id);
