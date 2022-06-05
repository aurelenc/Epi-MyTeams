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

static char *is_user_connected(client_sock_t *clients, unsigned int user_id)
{
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i].user && clients[i].user->id == user_id)
            return "1";
    }
    return "0";
}

static char *get_msg_reply(llist_t *users, client_sock_t *clients)
{
    node_t *ptr = users->first;
    char *buff = calloc(sizeof(char), MAX_BUFF_SIZE + 1);

    strcat(buff, "00:");
    while (ptr && strlen(buff) < MAX_BUFF_SIZE +
    strlen(((user_t *)ptr->data)->uuid) +
    strlen(((user_t *)ptr->data)->pseudo) + 12) {
        strcat(buff, "[ \"");
        strcat(buff, ((user_t *)ptr->data)->uuid);
        strcat(buff, "\" \"");
        strcat(buff, ((user_t *)ptr->data)->pseudo);
        strcat(buff, "\" \"");
        strcat(buff, is_user_connected(clients, ((user_t *)ptr->data)->id));
        strcat(buff, "\"]");
        ptr = ptr->next;
    }
    return (buff);
}

int command_users(TEAMS_A)
{
    char *success_buff = 0;

    printf("[SERVER] USERS\n");
    if (!THIS_CLIENT.user)
        return client_reply(PARAM_CID, FORBIDDEN, EMPTY_REPLY);
    if (param->arg.nb > 1) {
        return client_reply(PARAM_CID, INVALID_FORMAT, EMPTY_REPLY);
    }
    success_buff = get_msg_reply(THIS_DB->users, TEAMS_CLIENTS);
    client_reply(PARAM_CID, SUCCESS, success_buff);
    return SUCCESS;
}
