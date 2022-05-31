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
#include "tables/users/user.h"
#include "tables/users/database_users_add.h"
#include "tables/users/database_users_search.h"

static char *get_reply_msg(char *user_uuid, char *user_name)
{
    char *reply = calloc(sizeof(char), strlen(user_uuid) + 9);

    strcat(reply, "[ \"");
    strcat(reply, user_uuid);
    strcat(reply, "\" \"");
    strcat(reply, user_name);
    strcat(reply, "\"]");
    return (reply);
}

int command_login(command_param_t *param)
{
    char success_buff[MAX_BUFF_SIZE] = {0};
    char *reply = 0;
    user_t *user = 0;

    printf("[SERVER] LOGIN\n");
    if (param->arg.nb < 2) {
        return client_reply(param->clients, param->id, MISSING_PARAMETER);
    } else if (param->arg.nb > 2) {
        return client_reply(param->clients, param->id, INVALID_FORMAT);
    }
    user = db_search_user_by_pseudo(param->srv->db, param->arg.array[2]);
    if (user) {
        // add user data this to client
    } else {
        user = user_init(llist_get_size(param->srv->db->users), param->arg.array[1], "");
        db_add_user(param->srv->db, user);
        // add user data this to client
    }
    reply = get_reply_msg(user->uuid, user->pseudo);
    sprintf(success_buff, reply_codes[get_reply(SUCCESS)].message, reply);
    free(reply);
    return client_reply_success(param->clients, param->id, success_buff);
}
