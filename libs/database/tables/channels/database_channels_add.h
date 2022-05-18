/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** database_channels_add
*/

#pragma once

#include "database.h"
#include "channel.h"

///
/// @brief It adds a channel to the database
///
/// @param db The database object
/// @param channel The channel to add to the database.
///
/// @return A boolean value.
///
static inline bool db_add_channel(database_t *db, channel_t *channel)
{
    return llist_append(db->channels, channel);
};
