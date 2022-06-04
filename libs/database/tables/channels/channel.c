/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** channel
*/

#include "channel.h"
#include "tables/uuid_gen.h"
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

channel_t *channel_init(const char *name, const char *desc, id_t team_id)
{
    channel_t *channel = calloc(sizeof(channel_t), 1);

    if (!channel) {
        perror("Channel creation");
        exit(84);
    }
    channel->id = 0;
    channel->name = strdup(name);
    channel->desc = strdup(desc);
    channel->uuid = uuid_gen();
    if (!channel->name || !channel->desc || !channel->uuid)
        exit(84);
    channel->team_id = team_id;
    return channel;
}

void channel_destruction(channel_t *channel)
{
    if (!channel)
        return;
    free(channel->name);
    free(channel->desc);
    free(channel->uuid);
    free(channel);
}
