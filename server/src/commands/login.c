/*
** EPITECH PROJECT, 2022
** Epi-MyTeams
** File description:
** login
*/

#include "reply_codes.h"
#include "server.h"
#include <stdio.h>

int command_login(command_param_t *param)
{
    // char *user_uid;
    // char reply[MAX_BUFF_SIZE];

    printf("[SERVER] LOGIN\n");
    if (param->arg.nb < 2) {
        return client_reply(param->clients, param->id, MISSING_PARAMETER);
    } else if (param->arg.nb > 2) {
        return client_reply(param->clients, param->id, INVALID_FORMAT);
    }
    return client_reply(param->clients, param->id, SUCCESS);
    // param->clients[param->id].user = param->arg.array[1];
    // server_event_user_logged_in(user_uid)
    // write_client_buff(param->clients, param->id, "777\n");
}
