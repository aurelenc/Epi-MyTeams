/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** channel
*/

#pragma once

typedef unsigned int id_t;

typedef struct channel_s {
    id_t id;
    char *name;
    id_t team_id;
} channel_t;

///
/// @brief It creates a channel
///
/// @param id the id of the channel
/// @param name The name of the channel.
/// @param team_id The id of the team the channel belongs to.
///
/// @return A pointer to a channel_t struct.
///
channel_t *channel_init(id_t id, const char *name);

///
/// @brief It frees the memory allocated for the name of the channel
///
/// @param channel The channel to destroy.
///
/// @return A pointer to a channel_t struct.
///
void channel_destruction(channel_t *channel);
