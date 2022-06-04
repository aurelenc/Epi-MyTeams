/*
** EPITECH PROJECT, 2022
** Epi-MyTeams
** File description:
** create_channel
*/

#include "logging_server.h"
#include "reply_codes.h"
#include "server.h"
#include "tables/users_x_teams/database_users_x_teams_search.h"
#include "tables/channels/database_channels_add.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static bool is_in_team(command_param_t *param)
{
    id_pair_t pair;
    id_pair_t *search = 0;

    if (!THIS_CLIENT.team)
        return false;
    pair.team_id = THIS_CLIENT.team->id;
    pair.user_id = THIS_CLIENT.user->id;
    search = db_search_user_team_by_pair(param->srv->db, &pair);
    if (!search)
        return false;
    return true;
}

static char *get_success(channel_t *channel)
{
    int len = strlen(channel->uuid) + strlen(channel->name) +
    strlen(channel->desc) + 16;
    char *buff = calloc(sizeof(char), len);

    snprintf(buff, len, "[ \"%s\" \"%s\" \"%s\"]\n", channel->uuid,
    channel->name, channel->desc);
    printf("%s\n", buff);
    return (buff);
}

int command_create_channel(TEAMS_A)
{
    channel_t *channel = 0;
    char *buff = 0;

    if (param->arg.nb < 3) {
        return client_reply(param->clients, param->id, MISSING_PARAMETER, "");
    } else if (param->arg.nb > 3) {
        return client_reply(param->clients, param->id, INVALID_FORMAT, "");
    }
    if (!is_in_team(param))
        return client_reply(PARAM_CID, FORBIDDEN, EMPTY_REPLY);
    channel = channel_init(THIS_ARG[1], THIS_ARG[2], THIS_CLIENT.team->id);
    server_event_channel_created(THIS_CLIENT.team->uuid, channel->uuid,
    channel->name);
    db_add_channel(THIS_DB, channel);
    buff = get_success(channel);
    client_reply(param->clients, param->id, CREATE_CHANNEL, buff);
    free(buff);
    return CREATE_CHANNEL;
}
