/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** database_channels_search
*/

#pragma once

#include "database.h"
#include "channel.h"
#include "channel_search.h"

///
/// @brief It searches the database for a channel with the given id
///
/// @param db The database to search in.
/// @param id The id of the channel to search for.
///
/// @return A pointer to a channel_t struct.
///
static inline channel_t *db_search_channel_by_id(database_t *db, const id_t id)
{
    return (channel_t *)llist_search(db->channels, &channel_id_compare, &id);
};

///
/// @brief It searches the database for a channel with the given uuid
///
/// @param db The database to search in.
/// @param uuid The uuid of the channel to search for.
///
/// @return A pointer to a channel_t struct.
///
static inline channel_t *db_search_channel_by_uuid(database_t *db,
const char *uuid)
{
    return
    (channel_t *)llist_search(db->channels, &channel_uuid_compare, uuid);
};

///
/// @brief It searches the database's
///channel list for a channel with the given team ID
///
/// @param db The database to search in.
/// @param team_id The team ID to search for.
///
/// @return A pointer to a channel_t struct.
///
static inline channel_t *db_search_channel_by_team_id(database_t *db,
const id_t team_id)
{
    return (channel_t *)llist_search(db->channels, &channel_team_id_compare,
    &team_id);
};
