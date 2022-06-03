/*
** EPITECH PROJECT, 2022
** Epi-MyTeams
** File description:
** create_channel
*/

#include "reply_codes.h"
#include "server.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char *get_success(TEAMS_A)
{
    int len = strlen(THIS_CLIENT.channel->uuid) +
    strlen(THIS_CLIENT.channel->name) + strlen(THIS_CLIENT.channel->desc) + 16;
    char *buff = calloc(sizeof(char), len);

    snprintf(buff, len, "51:[ \"%s\" \"%s\" \"%s\"]\n", THIS_CLIENT.channel->uuid,
    THIS_CLIENT.channel->name, THIS_CLIENT.channel->desc);
    printf("%s\n", buff);
    return (buff);
}

int command_create_channel(TEAMS_A)
{
    char *buff = get_success(param);
    free(buff);
    return NOT_IMPLEMENTED;
}
