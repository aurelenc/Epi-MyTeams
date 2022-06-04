/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** database_channels_save
*/

#include "database.h"
#include "database_channels_add.h"
#include "channel.h"
#include "tables/load_functions.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

static void write_all_channels_in_file(llist_t *channels, FILE *fptr)
{
    node_t *nptr = channels->first;
    channel_t *channel;

    while (nptr) {
        channel = (channel_t *)nptr->data;
        fprintf(fptr, "\"%i\";\"%s\";\"%s\";\"%s\";\"%i\";\n", channel->id,
        channel->uuid, channel->name, channel->desc, channel->team_id);
        nptr = nptr->next;
    }
}

bool db_save_channels(database_t *db, const char *filepath)
{
    FILE *fptr;

    fptr = fopen(filepath, "w");
    if (fptr == NULL) {
        printf("Unable to open file.\n");
        return false;
    }
    write_all_channels_in_file(db->channels, fptr);
    fclose(fptr);
    printf("Channels: Successfully saved.\n");
    return true;
}

bool db_load_channels(database_t *db, const char *filepath)
{
    char *content = get_file_content(filepath);
    char ***entities = 0;
    channel_t *channel = 0;

    if (!content)
        return false;
    entities = get_entities(content, 5);
    if (!entities)
        return false;
    for (size_t i = 0; entities[i]; i++) {
        channel = channel_init(entities[i][2],
        entities[i][3], atoi(entities[i][4]));
        free(channel->uuid);
        channel->uuid = entities[i][1];
        channel->id = atoi(entities[i][0]);
        db_add_channel(db, channel);
    }
    printf("Channels: Successfully loaded.\n");
    return true;
}
