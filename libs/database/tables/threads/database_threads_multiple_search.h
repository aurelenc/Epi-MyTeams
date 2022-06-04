/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** database_threads_multiple_search
*/

#pragma once

#include "database.h"

typedef unsigned int id_t;

///
/// It searches for threads in a database by channel id
///
/// @param db the database to search in
/// @param channel_id The id of the channel to search for.
///
/// @return A pointer to an allocated database_t structure with a thread field
/// filled
///
database_t *db_multiple_search_threads_by_channel_id(database_t *db,
const id_t channel_id);

///
/// It searches for threads in a database by title
///
/// @param db the database to search in
/// @param title The title to search for.
///
/// @return A pointer to an allocated database_t structure with a thread field
/// filled
///
database_t *db_multiple_search_threads_by_title(database_t *db,
const char *title);
