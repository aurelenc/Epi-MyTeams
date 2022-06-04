/*
** EPITECH PROJECT, 2022
** Epi-MyTeams
** File description:
** subscribed
*/

#include "reply_codes.h"
#include "server.h"
#include "commands.h"

int command_subscribed(TEAMS_A)
{
    if (!THIS_CLIENT.user)
        return client_reply(PARAM_CID, FORBIDDEN, "");
    if (TEAMS_PARAM->arg.nb == 1)
        return command_subscribed_teams(TEAMS_PARAM);
    else if (TEAMS_PARAM->arg.nb == 2)
        return command_subscribed_users(TEAMS_PARAM);
    else
        return client_reply(PARAM_CID, INVALID_FORMAT, "");
}
