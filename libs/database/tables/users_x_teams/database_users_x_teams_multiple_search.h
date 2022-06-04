/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** database_users_x_teams_multiple_search
*/

#pragma once

#include "database.h"

typedef unsigned int id_t;

///
/// @brief It searches for all the users of a team by its id
///
/// @param db the database
/// @param id the id of the team you want to search for
///
/// @return A pointer to an allocated database_t structure
///
database_t *db_search_users_of_a_team_by_its_id(database_t *db,
const id_t id);

///
/// It searches for the teams of an user by his id
///
/// @param db the database
/// @param id the id of the user
///
/// @return A pointer to an allocated database_t structure
///
database_t *db_search_teams_of_an_user_by_his_id(database_t *db,
const id_t id);
