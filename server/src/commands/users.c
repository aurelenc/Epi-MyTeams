/*
** EPITECH PROJECT, 2022
** Epi-MyTeams
** File description:
** users
*/

#include "reply_codes.h"
#include "server.h"
#include "tables/users/user.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

static char *get_msg_reply(llist_t *users)
{
    node_t *ptr = users->first;
    char *buff = calloc(sizeof(char), MAX_BUFF_SIZE);

    strcat(buff, "00 ");
    while (ptr && strlen(buff) < MAX_BUFF_SIZE + strlen(((user_t *)ptr)->uuid)
    + strlen(((user_t *)ptr)->pseudo) + 12) {
        strcat(buff, "[ \"");
        strcat(buff,   ((user_t *)ptr)->uuid);
        strcat(buff, "\" \"");
        strcat(buff, ((user_t *)ptr)->pseudo);
        strcat(buff, "\" \"");
        strcat(buff, "0" ); // add here connection status
        strcat(buff, "\"]");
        ptr = ptr->next;
    }
    return (buff);
}

int command_users(command_param_t *param)
{
    char *success_buff = 0;

    printf("[SERVER] USERS\n");
    if (param->arg.nb > 1) {
        return client_reply(param->clients, param->id, INVALID_FORMAT);
    }
    success_buff = get_msg_reply(param->srv->db->users);
    return client_reply_success(param->clients, param->id, success_buff);
}
