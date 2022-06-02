/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** database_threads_save
*/

#pragma once

#include "database.h"

///
/// @brief It opens a file, writes all the threads in the database to the file,
/// closes the file
///
/// @param db The database object.
/// @param filepath The path to the file to save the threads to.
///
/// @return A boolean value.
///
bool db_save_threads(database_t *db, const char *filepath);

///
/// @brief It reads a file and creates a channel for each line
///
/// @param db the database
/// @param filepath The path to the file to load.
///
/// @return A boolean value.
///
bool db_load_threads(database_t *db, const char *filepath);
