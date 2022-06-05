/*
** EPITECH PROJECT, 2022
** Epi-MyTeams
** File description:
** info_user
*/

#include "reply_codes.h"
#include "server.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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

int command_info_user(TEAMS_A)
{
    char *message = get_msg_reply(THIS_CLIENT.user, TEAMS_CLIENTS);

    client_reply(PARAM_CID, PRINT_ALL_USERS, message);
    free(message);
    return PRINT_ALL_USERS;

}
