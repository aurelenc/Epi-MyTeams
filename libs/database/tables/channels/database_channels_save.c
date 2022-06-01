/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** database_channels_save
*/

#include "database.h"
#include "channel.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

static void write_all_channels_in_file(llist_t *channels, FILE *fptr)
{
    node_t *nptr = channels->first;
    channel_t *channel;

    while (nptr) {
        channel = (channel_t *)nptr->data;
        fprintf(fptr,"\"%i\";\"%s\";\"%s\";\"%s\";\"%i\";\n", channel->id,
        channel->uuid, channel->name, channel->desc, channel->team_id);
        nptr = nptr->next;
    }
}

bool save_channels(database_t *db, const char *filepath)
{
    FILE *fptr;

    fptr = fopen(filepath, "w");
    if (fptr == NULL) {
        printf("Unable to create file.\n");
        return false;
    }
    write_all_channels_in_file(db->channels, fptr);
    fclose(fptr);
    printf("Channels saved successfully.\n");
    return true;
}
