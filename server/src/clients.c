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
#include "database_management.h"

static void set_client_strings(client_sock_t *clients, int id)
{
    memset(clients[id].rbuf, 0, CIRCULAR_BUFFER_SIZE);
    memset(clients[id].wbuf, 0, CIRCULAR_BUFFER_SIZE);
}

void new_client(client_sock_t *clients, int client_socket)
{
    int i = 0;

    for (; i < MAX_CLIENTS - 1 && clients[i].socket != 0; i++);
    if (clients[i].socket) {
        return;
    }
    clients[i].socket = client_socket;
    set_client_strings(clients, i);
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
    printf("[WRITE] %s\n", buff);
    write(client->socket, buff, strlen(buff));
}

void listen_clients(client_sock_t *clients, server_t *server)
{
    for (int i = 0; i < MAX_CLIENTS && clients[i].socket != 0; i++) {
        if (FD_ISSET(clients[i].socket, &server->rfd))
            handle_input(clients, i, server);
        if (FD_ISSET(clients[i].socket, &server->wfd)) {
            write_to_client(&clients[i]);
            db_save(server->db);
        }
    }
}
