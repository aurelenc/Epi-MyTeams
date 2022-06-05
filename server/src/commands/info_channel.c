/*
** EPITECH PROJECT, 2022
** Epi-MyTeams
** File description:
** info_channel
*/

#include "reply_codes.h"
#include "server.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static char *get_msg_reply(channel_t *channel, client_sock_t *clients)
{
    char *buff = calloc(sizeof(char), MAX_BUFF_SIZE + 1);

    snprintf(buff, MAX_BUFF_SIZE, "[\"%s\" \"%s\" \"%s\"]",
    channel->uuid, channel->name, channel->desc);
    printf("%s\n", buff);
    return (buff);
}

int command_info_channel(TEAMS_A)
{
    char *message = get_msg_reply(THIS_CLIENT.channel, TEAMS_CLIENTS);

    client_reply(PARAM_CID, PRINT_ALL_CHANNELS, message);
    free(message);
    return SUCCESS;
}
