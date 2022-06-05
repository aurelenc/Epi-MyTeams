/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** use
*/

#include "reply_codes.h"
#include "server.h"
#include "commands.h"

int command_use(TEAMS_A)
{
    if (!THIS_CLIENT.user)
        return client_reply(PARAM_CID, FORBIDDEN, EMPTY_REPLY);
    if (param->arg.nb == 1)
        return command_use_nothing(param);
    if (param->arg.nb == 2)
        return command_use_one_arg(param);
    if (param->arg.nb == 3)
        return command_use_two_arg(param);
    if (param->arg.nb == 4)
        return command_use_three_arg(param);
    return client_reply(PARAM_CID, INVALID_FORMAT, EMPTY_REPLY);
}
