/*
** EPITECH PROJECT, 2022
** Epi-MyTeams
** File description:
** login
*/

#include "reply_codes.h"
#include "server.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"
#include "database_users_add.h"

static char *get_reply_msg(char *user_uuid)
{
    char *reply = calloc(sizeof(char), strlen(user_uuid) + 3);

    strcat(reply, "[");
    strcat(reply, user_uuid);
    strcat(reply, "]");
    return (reply);
}

int command_login(command_param_t *param)
{
    char success_buff[MAX_BUFF_SIZE] = {0};
    char *reply = 0;

    printf("[SERVER] LOGIN\n");
    if (param->arg.nb < 2) {
        return client_reply(param->clients, param->id, MISSING_PARAMETER);
    } else if (param->arg.nb > 2) {
        return client_reply(param->clients, param->id, INVALID_FORMAT);
    }
    db_add_user(param->srv->db,
    user_init(llist_get_size(param->srv->db->users), param->arg.array[1], ""));
    reply = get_reply_msg(((user_t *)llist_back(param->srv->db->users))->uuid);
    sprintf(success_buff, reply_codes[get_reply(SUCCESS)].message, reply);
    free(reply);
    return client_reply_success(param->clients, param->id, success_buff);
}
