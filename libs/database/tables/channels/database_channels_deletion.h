/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** database_channels_deletion
*/

#pragma once

#include "database.h"
#include "channel.h"
#include "channel_search.h"

///
/// @brief It deletes a channel from the database by its id
///
/// @param db The database to delete the channel from.
/// @param id The id of the channel to delete.
///
/// @return A boolean value.
///
static inline bool db_delete_channel_by_id(database_t *db, const id_t id)
{
    return llist_delif(db->channels, &channel_id_compare, &id);
}

///
/// @brief It deletes a channel from the database by uuid
///
/// @param db The database to delete the channel from.
/// @param uuid The uuid of the channel to delete.
///
/// @return A boolean value.
///
static inline bool db_delete_channel_by_uuid(database_t *db,
const char *uuid)
{
    return llist_delif(db->channels, &channel_uuid_compare, uuid);
}

///
/// @brief It deletes a channel from the database if it has the same team id
/// as the one passed in
///
/// @param db The database to delete the channel from.
/// @param team_id The id of the team to delete the channel of.
///
/// @return A boolean value.
///
static inline bool db_delete_channel_by_team_id(database_t *db,
const id_t team_id)
{
    return llist_delif(db->channels, &channel_team_id_compare, &team_id);
}
