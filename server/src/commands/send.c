/*
** EPITECH PROJECT, 2022
** Epi-MyTeams
** File description:
** send
*/

#include "reply_codes.h"
#include "server.h"
#include <unistd.h>

int command_send(command_param_t *param)
{
    return client_reply(param->clients, param->id, SUCCESS);
    // write(param->clients[param->id].socket, "99\n", 4);
    // return NOT_IMPLEMENTED;
}
