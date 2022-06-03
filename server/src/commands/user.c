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
#include "components/command_head.h"

static char *is_user_connected(client_sock_t *clients, unsigned int user_id)
{
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i].user == user_id)
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

int command_user(TEAMS_A)
{
    COMMAND_HEAD("USERS", 2, 2)
    found = db_search_user_by_uuid(THIS_DB, THIS_ARG[1]);
    if (!found) {
        return client_reply(PARAM_CID, NOT_FOUND);
    }
    success_buff = get_msg_reply(found, TEAMS_CLIENTS);
    return client_reply_success(PARAM_CID, success_buff);
}
