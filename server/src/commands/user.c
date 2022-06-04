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
    strlen(user->uuid) + strlen(user->pseudo) + 16);

    strcat(buff, "00:");
    strcat(buff, "[ \"");
    strcat(buff, user->uuid);
    strcat(buff, "\" \"");
    strcat(buff, user->pseudo);
    strcat(buff, "\" \"");
    strcat(buff, is_user_connected(clients, user->id));
    strcat(buff, "\"]");
    printf("%s\n", buff);
    return (buff);
}

int command_user(TEAMS_A)
{
    char *success_buff = 0;
    user_t *found = 0;
    char user_id_formatted[UUID_SIZE + 7] = {0};

    printf("[SERVER] USER\n");
    if (!THIS_CLIENT.user)
        return client_reply(PARAM_CID, FORBIDDEN, EMPTY_REPLY);
    if (param->arg.nb < 2) {
        return client_reply(PARAM_CID, MISSING_PARAMETER, EMPTY_REPLY);
    } else if (param->arg.nb > 2) {
        return client_reply(PARAM_CID, INVALID_FORMAT, EMPTY_REPLY);
    }
    found = db_search_user_by_uuid(THIS_DB, THIS_ARG[1]);
    if (!found) {
        snprintf(user_id_formatted, UUID_SIZE + 6, "[ \"%s\"]", THIS_ARG[1]);
        return client_reply(PARAM_CID, NOT_FOUND, user_id_formatted);
    }
    success_buff = get_msg_reply(found, TEAMS_CLIENTS);
    client_reply(PARAM_CID, SUCCESS, success_buff);
    return SUCCESS;
}
