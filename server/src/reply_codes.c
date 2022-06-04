/*
** EPITECH PROJECT, 2022
** Epi-MyTeams
** File description:
** reply_codes
*/

#include "reply_codes.h"
#include "server.h"
#include <stdio.h>

const reply_code_t reply_codes[] = {
    {SUCCESS, "00:%s\n"},
    {SERVICE_READY_FOR_NEW_USER, "01:%s\n"},
    {SUBSCRIBE_OK, "02:%s\n"},
    {UNSUBSCRIBE_OK, "03:%s\n"},
    {INTERNAL_SERVER_ERROR, "10:%s\n"},
    {SERVER_IS_FULL, "11:%s\n"},
    {TOO_MANY_REQUESTS, "12:%s\n"},
    {FORBIDDEN, "13:%s\n"},
    {NOT_FOUND, "14:%s\n"},
    {UNKNOWN_CLIENT_ERROR, "20:%s\n"},
    {UNRECOGNIZED_COMMAND, "21:%s\n"},
    {MISSING_PARAMETER, "22:%s\n"},
    {INVALID_FORMAT, "23:%s\n"},
    {RESOURCE_ALREADY_EXISTS, "24:%s\n"},
    {UNKNOWN_TEAM, "30:%s\n"},
    {UNKNOWN_CHANNEL, "31:%s\n"},
    {UNKNOWN_THREAD, "32:%s\n"},
    {UNKNOWN_CLIENT, "33:%s\n"},
    {PRINT_ALL_USERS, "40:%s\n"},
    {PRINT_ALL_TEAMS, "41:%s\n"},
    {PRINT_ALL_CHANNELS, "42:%s\n"},
    {PRINT_ALL_THREADS, "43:%s\n"},
    {PRINT_ALL_REPLIES, "44:%s\n"},
    {CREATE_TEAM, "50:%s\n"},
    {CREATE_CHANNEL, "51:%s\n"},
    {CREATE_THREAD, "52:%s\n"},
    {CREATE_REPLY, "53:%s\n"},
    {GET_MESSAGE, "60:%s\n"},
    {GET_TEAM, "61:%s\n"},
    {GET_CHANNEL, "62:%s\n"},
    {GET_THREAD, "63:%s\n"},
    {GET_REPLY, "64:%s\n"},
    {NOT_IMPLEMENTED, "99:%s\n"},
};

int get_reply(int code)
{
    int i = 0;

    for (; reply_codes[i].code != NOT_IMPLEMENTED; i++) {
        if (reply_codes[i].code == code)
            return i;
    }
    return i;
}

int client_reply(client_sock_t *clients, int client_id, int code, char *msg)
{
    char buff[MAX_BUFF_SIZE] = {0};

    sprintf(buff, reply_codes[get_reply(SUCCESS)].message, msg);
    write_client_buff(clients, client_id, buff);
    return code;
}
