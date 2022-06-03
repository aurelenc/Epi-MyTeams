/*
** EPITECH PROJECT, 2022
** Epi-MyTeams
** File description:
** use_channel
*/

#include "reply_codes.h"
#include "server.h"
#include "tables/channels/database_channels_search.h"
#include "tables/users/user_search.h"
#include <string.h>

int command_use_channel(TEAMS_A)
{
    channel_t *channel = 0;

    if (param->arg.nb < 2)
        return client_reply(PARAM_CID, MISSING_PARAMETER);
    channel = db_search_channel_by_uuid(THIS_DB, THIS_ARG[1]);
    if (!channel)
        return client_reply(PARAM_CID, NOT_FOUND);
    if (channel->team_id == THIS_CLIENT.team_id) {
        THIS_CLIENT.channel_id = channel->id;
        THIS_CLIENT.thread_id = 0;
        return client_reply_success(PARAM_CID, "");
    }
    return client_reply(PARAM_CID, FORBIDDEN);
}
