/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** use_nothing
*/

#include "reply_codes.h"
#include "server.h"

int command_use_nothing(TEAMS_A)
{
    THIS_CLIENT.team = 0;
    THIS_CLIENT.channel = 0;
    THIS_CLIENT.thread = 0;
    return client_reply(PARAM_CID, SUCCESS, EMPTY_REPLY);
}
