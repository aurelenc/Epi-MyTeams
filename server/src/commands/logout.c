/*
** EPITECH PROJECT, 2022
** Epi-MyTeams
** File description:
** logout
*/

#include "reply_codes.h"
#include "server.h"
#include <stdio.h>

int command_logout(command_param_t *param)
{
    printf("[SERVER] LOGIN\n");
    server_event_user_logged_out(param->clients[param->id].user);
    remove_client(param->clients, param->id);
}
