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
/// @brief It frees all the linked lists in the database
///
/// @param database the database to destroy
///
/// @return A pointer to a database_t struct.
///
database_t *db_destruction(database_t *database);
