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
    printf("login\n");
    write_client_buff(param->clients, param->id, "logged in\n");
    return REPLY_NOT_IMPLEMENTED;
}
