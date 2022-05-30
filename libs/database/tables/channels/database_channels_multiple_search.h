/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** database_channels_multiple_search
*/

#pragma once

#include "database.h"

typedef unsigned int id_t;

///
/// It searches for channels in the database that have the same team_id as the one
/// passed as a parameter
///
/// @param db the database to search in
/// @param team_id The id of the team you want to search for.
///
/// @return A pointer to an allocated database_t structure with a channel field
/// filled
///
database_t *db_multiple_search_channel_by_team_id(database_t *db,
const id_t team_id);
