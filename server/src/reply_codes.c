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
    {SERVICE_READY_FOR_NEW_USER, "01:[ \"Service ready for new user.\"]\n"},
    {INTERNAL_SERVER_ERROR, "10:[ \"Internal server error.\"]\n"},
    {SERVER_IS_FULL, "11:[ \"Server is full.\"]\n"},
    {TOO_MANY_REQUESTS, "12:[ \"Too many requests.\"]\n"},
    {FORBIDDEN, "13:[ \"Forbidden.\"]\n"},
    {NOT_FOUND, "14:[ \"Not found.\"]\n"},
    {UNKNOWN_CLIENT_ERROR, "20:[ \"Unknown client error.\"]\n"},
    {UNRECOGNIZED_COMMAND, "21:[ \"Unrecognized command.\"]\n"},
    {MISSING_PARAMETER, "22:[ \"Missing parameter.\"]\n"},
    {INVALID_FORMAT, "23:[ \"Invalid format.\"]\n"},
    {RESOURCE_ALREADY_EXISTS, "24:[ \"Resource already exists.\"]\n"},
    {NOT_IMPLEMENTED, "99:[ \"Not implemented.\"]\n"},
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
