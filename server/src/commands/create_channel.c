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
#include "tables/channels/database_channels_multiple_search.h"
#include "tables/channels/database_channels_search.h"
#include "database_management.h"
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

static int send_success(TEAMS_A, channel_t *channel)
{
    int len = strlen(channel->uuid) + strlen(channel->name) +
    strlen(channel->desc) + 16;
    char *buff = calloc(sizeof(char), len);

    snprintf(buff, len, "[ \"%s\" \"%s\" \"%s\"]", channel->uuid,
    channel->name, channel->desc);
    printf("%s\n", buff);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (TEAMS_CLIENTS[i].socket == 0 || !TEAMS_CLIENTS[i].user)
            continue;
        if (i == param->id)
            client_reply(param->clients, i, CREATE_CHANNEL, buff);
        else
            client_reply(param->clients, i, GET_CHANNEL, buff);
    }
    free(buff);
    return (CREATE_CHANNEL);
}

static bool channel_already_exists(TEAMS_A)
{
    database_t *found = db_multiple_search_channel_by_name(THIS_DB,
    THIS_ARG[1]);
    bool retval = false;

    if (db_search_channel_by_team_id(found, THIS_CLIENT.team->id))
        retval = true;
    free(found->channels);
    free(found->discussions);
    free(found->users_teams);
    free(found->users);
    free(found->threads);
    free(found->messages);
    free(found->teams);
    return retval;
}

static int send_already_exists(TEAMS_A)
{
    int len = strlen(THIS_ARG[1]) + strlen(THIS_ARG[2]) + 13;
    char *buff = calloc(sizeof(char), len);
    int retval = -1;

    snprintf(buff, len, "[ \"%s\" \"%s\"]", THIS_ARG[1], THIS_ARG[2]);
    printf("%s\n", buff);
    retval = client_reply(PARAM_CID, RESOURCE_ALREADY_EXISTS, buff);
    free(buff);
    return retval;
}

int command_create_channel(TEAMS_A)
{
    channel_t *channel = 0;

    if (param->arg.nb < 3) {
        return client_reply(param->clients, param->id, MISSING_PARAMETER, "");
    } else if (param->arg.nb > 3) {
        return client_reply(param->clients, param->id, INVALID_FORMAT, "");
    }
    if (!is_in_team(param))
        return client_reply(PARAM_CID, FORBIDDEN, EMPTY_REPLY);
    if (channel_already_exists(param))
        return send_already_exists(param);
    channel = channel_init(THIS_ARG[1], THIS_ARG[2], THIS_CLIENT.team->id);
    server_event_channel_created(THIS_CLIENT.team->uuid, channel->uuid,
    channel->name);
    db_add_channel(THIS_DB, channel);
    return send_success(param, channel);
}
