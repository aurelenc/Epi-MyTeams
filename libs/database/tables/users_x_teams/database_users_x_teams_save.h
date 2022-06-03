/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** database_users_x_teams_save
*/

#pragma once

#include "database.h"

///
/// @brief It opens a file, writes all the users_x_teams in the database to the file,
/// closes the file
///
/// @param db The database object.
/// @param filepath The path to the file to save the users_x_teams to.
///
/// @return A boolean value.
///
bool db_save_users_x_teams(database_t *db, const char *filepath);

///
/// @brief It reads a file and creates a channel for each line
///
/// @param db the database
/// @param filepath The path to the file to load.
///
/// @return A boolean value.
///
bool db_load_users_x_teams(database_t *db, const char *filepath);
