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
    user_t *user = db_search_user_by_id(param->srv->db, THIS_CLIENT.user);

    if (user)
        server_event_user_logged_out(user->uuid);
    remove_client(param->clients, param->id);
    return SUCCESS;
}
