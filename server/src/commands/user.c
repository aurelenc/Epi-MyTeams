/*
** EPITECH PROJECT, 2022
** Epi-MyTeams
** File description:
** user
*/

#include "reply_codes.h"
#include "server.h"
#include "tables/users/database_users_search.h"

static void fill_msg_reply(user_t *user, char **buff)
{
    strcat(*buff, "00 ");
    strcat(*buff, "[ \"");
    strcat(*buff,   user->uuid);
    strcat(*buff, "\" \"");
    strcat(*buff, user->pseudo);
    strcat(*buff, "\" \"");
    strcat(*buff, "0" );
    strcat(*buff, "\"]");
}

int command_user(command_param_t *param)
{
    char success_buff[MAX_BUFF_SIZE] = {0};
    char *reply = 0;
    user_t *found = 0;

    printf("[SERVER] USERS\n");
    if (param->arg.nb > 1) {
        return client_reply(param->clients, param->id, INVALID_FORMAT);
    }
    found = db_search_user_by_uuid(param->srv->db, param->arg.array[1]);
    if (!found) {
        return client_reply(param->clients, param->id, NOT_FOUND);
    }
    fill_msg_reply(found, &success_buff);
    return client_reply_success(param->clients, param->id, success_buff);
}
