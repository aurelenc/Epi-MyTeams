/*
** EPITECH PROJECT, 2022
** Epi-MyTeams
** File description:
** users
*/

#include "reply_codes.h"
#include "server.h"
#include "tables/users/user.h"

static void fill_msg_reply(llist_t *users, char *buff[MAX_BUFF_SIZE])
{
    node_t *ptr = users->first;

    strcat(*buff, "00 ");
    while (ptr && strlen(*buff) < MAX_BUFF_SIZE) {
        strcat(*buff, "[ \"");
        strcat(*buff,   ((user_t *)ptr)->uuid);
        strcat(*buff, "\" \"");
        strcat(*buff, ((user_t *)ptr)->pseudo);
        strcat(*buff, "\" \"");
        strcat(*buff, "0" );
        strcat(*buff, "\"]");
        ptr = ptr->next;
    }
}

int command_users(command_param_t *param)
{
    char success_buff[MAX_BUFF_SIZE] = {0};
    char *reply = 0;

    printf("[SERVER] USERS\n");
    if (param->arg.nb > 1) {
        return client_reply(param->clients, param->id, INVALID_FORMAT);
    }
    fill_msg_reply(param->srv->db->users, &success_buff);
    return client_reply_success(param->clients, param->id, success_buff);
}
