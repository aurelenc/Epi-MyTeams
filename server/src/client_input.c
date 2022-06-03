/*
** EPITECH PROJECT, 2022
** Epi-MyTeams
** File description:
** client_input
*/

#include "server.h"
#include "reply_codes.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "circular_buffer.h"
#include <stdio.h>

void write_client_buff(client_sock_t *clients, int i, char *message)
{
    if (cbuff_push(clients[i].wbuf, message) == BUFFER_FULL)
        remove_client(clients, i);
}

int get_command_params(char **dest, char *src)
{
    int i = 0;
    char *tmp = strdup(src);
    char *tok;

    for (; i < MAX_PARAMS_NB; i++) {
        tok = strtok(i == 0 ? tmp : NULL, " \t\r\n");
        if (!tok)
            break;
        dest[i] = strdup(tok);
        if (!dest[i])
            break;
    }
    free(tmp);
    return i;
}

void exec_cmd(TEAMS_A, int cmd_id)
{
    commands[cmd_id].func(TEAMS_PARAM);
}

void find_command(TEAMS_A)
{
    bool command_found = false;
    char buff[MAX_BUFF_SIZE] = {0};

    printf("%s\n", THIS_CLIENT.rbuf);
    if (cbuff_pop(THIS_CLIENT.rbuf, buff, MAX_BUFF_SIZE) != BUFFER_OK)
        return;
    for (size_t i = 0; commands[i].func != NULL; i++) {
        printf("%s\t%s:%ld\n", buff, commands[i].cmd, strlen(commands[i].cmd));
        if (strncmp(buff, commands[i].cmd,
            strlen(commands[i].cmd)) == 0) {
            exec_cmd(TEAMS_PARAM, i);
            command_found = true;
            break;
        }
    }
    if (!command_found)
        write_client_buff(PARAM_CID,
        reply_codes[get_reply(550)].message);
}

void handle_input(client_sock_t *clients, int id, server_t *server)
{
    params_t params;
    command_param_t command_params;
    char buff[MAX_BUFF_SIZE] = {0};

    params.nb = 0;
    params.array = calloc(sizeof(char *), MAX_PARAMS_NB + 1);
    if (!params.array ||
        read(clients[id].socket, buff, MAX_BUFF_SIZE) == 0) {
        remove_client(clients, id);
        return;
    }
    cbuff_push(clients[id].rbuf, buff);
    params.nb = get_command_params(params.array, clients[id].rbuf);
    command_params.clients = clients;
    command_params.id = id;
    command_params.srv = server;
    command_params.arg = params;
    find_command(&command_params);
    free(params.array);
}
