/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** channel
*/

#include "channel.h"
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

channel_t *channel_init(id_t id, const char *name, id_t team_id)
{
    channel_t *channel = calloc(sizeof(channel_t), 1);

    if (!channel) {
        perror("Channel creation");
        exit (84);
    }
    channel->id = id;
    channel->team_id = team_id;
    channel->name = strdup(name);
    if (!channel->name) {
        perror("Channel creation");
        exit (84);
    };
    return channel;
}

void channel_destruction(channel_t *channel)
{
    if (!channel)
        return;
    free(channel->name);
}
