/*
** EPITECH PROJECT, 2022
** Epi-MyTeams
** File description:
** user
*/

#include "reply_codes.h"
#include "server.h"
#include "tables/users/database_users_search.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static char *is_user_connected(client_sock_t *clients, unsigned int user_id)
{
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i].user && clients[i].user->id == user_id)
            return "1";
    }
    return "0";
}

static char *get_msg_reply(user_t *user, client_sock_t *clients)
{
    char *buff = calloc(sizeof(char),
    strlen(user->uuid) + strlen(user->pseudo) + 13);

    strcat(buff, "00:");
    strcat(buff, "[ \"");
    strcat(buff,   user->uuid);
    strcat(buff, "\" \"");
    strcat(buff, user->pseudo);
    strcat(buff, "\" \"");
    strcat(buff, is_user_connected(clients, user->id));
    strcat(buff, "\"]");
    return (buff);
}

int command_user(command_param_t *param)
{
    char *success_buff = 0;
    user_t *found = 0;

    printf("[SERVER] USER\n");
    if (param->arg.nb < 2) {
        return client_reply(param->clients, param->id, MISSING_PARAMETER);
    } else if (param->arg.nb > 2) {
        return client_reply(param->clients, param->id, INVALID_FORMAT);
    }
    if (!THIS_CLIENT.user)
        return client_reply(PARAM_CID, FORBIDDEN);
    found = db_search_user_by_uuid(param->srv->db, param->arg.array[1]);
    if (!found) {
        return client_reply(param->clients, param->id, NOT_FOUND);
    }
    success_buff = get_msg_reply(found, param->clients);
    return client_reply_success(param->clients, param->id, success_buff);
}
