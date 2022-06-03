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
        return client_reply(PARAM_CID, FORBIDDEN);
    if (THIS_CLIENT.thread_id)
        return command_create_reply(param);
    if (THIS_CLIENT.channel_id)
        return command_create_thread(param);
    if (THIS_CLIENT.team_id)
        return command_create_channel(param);
    return command_create_team(param);
}
