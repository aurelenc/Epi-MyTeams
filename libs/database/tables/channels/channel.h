/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** channel
*/

#pragma once

#include <uuid/uuid.h>

typedef unsigned int id_t;

typedef struct channel_s {
    id_t id;
    char *uuid;
    char *name;
    char *desc;
    id_t team_id;
} channel_t;

///
/// @brief It creates a channel
///
/// @param name The name of the channel.
/// @param desc The description of the channel.
/// @param team_id The id of the team the channel belongs to.
///
/// @return A pointer to a channel_t struct.
///
channel_t *channel_init(const char *name, const char *desc, id_t team_id);

///
/// @brief It frees the memory allocated for the name of the channel
///
/// @param channel The channel to destroy.
///
/// @return A pointer to a channel_t struct.
///
void channel_destruction(channel_t *channel);
