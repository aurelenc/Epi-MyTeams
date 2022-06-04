/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** create
*/

#include "reply_codes.h"
#include "server.h"
#include "commands.h"

int command_create(command_param_t *param)
{
    if (!THIS_CLIENT.user)
        return client_reply(PARAM_CID, FORBIDDEN, EMPTY_REPLY);
    if (THIS_CLIENT.thread) {
        if (!THIS_CLIENT.team)
            return client_reply(PARAM_CID, UNKNOWN_TEAM, EMPTY_REPLY);
        if (!THIS_CLIENT.channel)
            return client_reply(PARAM_CID, UNKNOWN_CHANNEL, EMPTY_REPLY);
        return command_create_reply(param);
    }
    if (THIS_CLIENT.channel) {
        if (!THIS_CLIENT.team)
            return client_reply(PARAM_CID, UNKNOWN_TEAM, EMPTY_REPLY);
        return command_create_thread(param);
    }
    if (THIS_CLIENT.team)
        return command_create_channel(param);
    return command_create_team(param);
}
