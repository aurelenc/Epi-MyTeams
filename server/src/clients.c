/*
** EPITECH PROJECT, 2022
** Epi-MyTeams
** File description:
** clients
*/

#include "server.h"
#include "reply_codes.h"
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include "circular_buffer.h"

static void set_client_strings(client_sock_t *clients, int id)
{
    memset(clients[id].rbuf, 0, MAX_BUFF_SIZE);
    memset(clients[id].wbuf, 0, MAX_BUFF_SIZE);
    memset(clients[id].user, 0, MAX_USER_SIZE);
}

void new_client(client_sock_t *clients, int client_socket)
{
    int i = 0;

    for (; i < MAX_CLIENTS - 1 && clients[i].socket != 0; i++);
    if (clients[i].socket) {
        dprintf(client_socket, reply_codes[get_reply(10068)].message);
        return;
    }
    clients[i].socket = client_socket;
    clients[i].team_id = 0;
    clients[i].channel_id = 0;
    clients[i].thread_id = 0;
    set_client_strings(clients, i);
    dprintf(client_socket, reply_codes[get_reply(220)].message);
}

void remove_client(client_sock_t *clients, int remove_index)
{
    shutdown(clients[remove_index].socket, SHUT_RDWR);
    close(clients[remove_index].socket);
    clients[remove_index].socket = 0;
}

void write_to_client(client_sock_t *client)
{
    char buff[MAX_BUFF_SIZE] = {0};

    if (cbuff_pop(client->wbuf, buff, MAX_BUFF_SIZE) == BUFFER_NO_DATA)
        return;
    write(client->socket, buff, strlen(buff));
}

void listen_clients(client_sock_t *clients, server_t *server)
{
    for (int i = 0; i < MAX_CLIENTS && clients[i].socket != 0; i++) {
        if (FD_ISSET(clients[i].socket, &server->rfd))
            handle_input(clients, i, server);
        // if (FD_ISSET(clients[i].socket, &server->wfd))
            write_to_client(&clients[i]);
    }
}
