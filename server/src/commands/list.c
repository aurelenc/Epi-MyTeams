/*
** EPITECH PROJECT, 2022
** Epi-MyTeams
** File description:
** list
*/

#include "reply_codes.h"
#include "server.h"
#include "commands.h"

int command_list(TEAMS_A)
{
    if (!THIS_CLIENT.user)
        return client_reply(PARAM_CID, FORBIDDEN, "");
    if (THIS_CLIENT.thread)
        return command_list_replies(TEAMS_PARAM);
    if (THIS_CLIENT.channel)
        return command_list_threads(TEAMS_PARAM);
    if (THIS_CLIENT.team)
        return command_list_channels(TEAMS_PARAM);
    return command_list_teams(TEAMS_PARAM);
}
