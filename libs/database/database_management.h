/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** database_management
*/

#pragma once

#include "database.h"

///
/// @brief It creates a database
///
/// @return A pointer to a database_t struct.
///
database_t *db_creation(void);

///
/// @brief It saves the database to a file
///
/// @param db the database to save
///
/// @return A boolean value.
///
bool db_save(database_t *db);

///
/// @brief It loads the database from the files in the database_save folder
///
/// @param db the database to load
///
/// @return A boolean value.
///
bool db_load(database_t *db)

///
/// @brief It frees all the linked lists in the database
///
/// @param database the database to destroy
///
/// @return A pointer to a database_t struct.
///
database_t *db_destruction(database_t *database);
