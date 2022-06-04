/*
** EPITECH PROJECT, 2022
** Epi-MyTeams
** File description:
** info
*/

#include "reply_codes.h"
#include "server.h"
#include "commands.h"

int command_info(TEAMS_A)
{
    if (!THIS_CLIENT.user)
        return client_reply(PARAM_CID, FORBIDDEN, "");
    if (THIS_CLIENT.thread)
        return command_info_thread(TEAMS_PARAM);
    if (THIS_CLIENT.channel)
        return command_info_channel(TEAMS_PARAM);
    if (THIS_CLIENT.team)
        return command_info_team(TEAMS_PARAM);
    return command_info_user(TEAMS_PARAM);
}
