/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** database_teams_save
*/

#pragma once

#include "database.h"

///
/// @brief It opens a file, writes all the teams in the database to the file,
/// closes the file
///
/// @param db The database object.
/// @param filepath The path to the file to save the teams to.
///
/// @return A boolean value.
///
bool db_save_teams(database_t *db, const char *filepath);

///
/// @brief It reads a file and creates a channel for each line
///
/// @param db the database
/// @param filepath The path to the file to load.
///
/// @return A boolean value.
///
bool db_load_teams(database_t *db, const char *filepath);
