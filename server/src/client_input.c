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

void write_client_buff(client_sock_t *clients, int i, char *message)
{
    if (strlen(clients[i].wbuf) + strlen(message) > MAX_BUFF_SIZE)
        remove_client(clients, i);
    strcat(clients[i].wbuf, message);
}

int get_command_params(char **dest, char *src)
{
    int i = 0;

    for (; i < MAX_PARAMS_NB; i++) {
        dest[i] = strtok(i == 0 ? src : NULL, " \t\r\n");
        if (!dest[i])
            break;
    }
    return i;
}

void exec_cmd(command_param_t *params)
{
    commands[params->id].func(params);
}

void find_command(command_param_t *params)
{
    bool command_found = false;

    for (size_t i = 0; commands[i].func != NULL; i++) {
        if (strncmp(params->clients[params->id].rbuf, commands[i].cmd,
            strlen(commands[i].cmd)) == 0) {
            exec_cmd(params);
            memset(params->clients[params->id].rbuf, 0, MAX_BUFF_SIZE);
            command_found = true;
            break;
        }
    }
    if (!command_found)
        write_client_buff(params->clients, params->id,
        reply_codes[get_reply(550)].message);
}

void handle_input(client_sock_t *clients, int id, server_t *server)
{
    params_t params;
    command_param_t command_params;

    params.nb = 0;
    params.array = calloc(sizeof(char *), MAX_PARAMS_NB + 1);
    if (!params.array ||
        read(clients[id].socket, clients[id].rbuf, MAX_BUFF_SIZE) == 0) {
        remove_client(clients, id);
        return;
    }
    params.nb = get_command_params(params.array, clients[id].rbuf);
    command_params.clients = clients;
    command_params.id = id;
    command_params.srv = server;
    command_params.arg = params;
    find_command(&command_params);
}
