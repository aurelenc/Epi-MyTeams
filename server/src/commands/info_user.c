/*
** EPITECH PROJECT, 2022
** Epi-MyTeams
** File description:
** info_user
*/

#include "reply_codes.h"
#include "server.h"

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

int command_info_user(TEAMS_A)
{
    char *message = get_msg_reply(THIS_CLIENT.user, TEAMS_CLIENTS);

    client_reply(PARAM_CID, SUCCESS, message);
    free(message);
    return SUCCESS;

}
