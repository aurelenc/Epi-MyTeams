/*
** EPITECH PROJECT, 2022
** Epi-MyTeams
** File description:
** logout
*/

#include "reply_codes.h"
#include "server.h"
#include <stdio.h>
#include "logging_server.h"
#include "tables/users/database_users_search.h"

int command_logout(command_param_t *param)
{
    if (THIS_CLIENT.user)
        server_event_user_logged_out(THIS_CLIENT.user->uuid);
    remove_client(param->clients, param->id);
    return SUCCESS;
}
