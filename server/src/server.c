/*
** EPITECH PROJECT, 2022
** Epi-MyTeams
** File description:
** server
*/

#include "server.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "database_management.h"

client_sock_t *init_clients(void)
{
    client_sock_t *clients = calloc(sizeof(client_sock_t), MAX_CLIENTS + 1);

    if (!clients)
        return NULL;
    for (int i = 0; i < MAX_CLIENTS; i++) {
        clients[i].socket = 0;
        clients[i].rbuf = calloc(sizeof(char), MAX_BUFF_SIZE);
        clients[i].wbuf = calloc(sizeof(char), MAX_BUFF_SIZE);
        clients[i].user = calloc(sizeof(char), UUID_SIZE + 1);
        if (!clients[i].rbuf || !clients[i].wbuf ||
            !clients[i].user)
            return NULL;
    }
    return clients;
}

int configure_server(server_t *server, char *port_param)
{
    server->db = db_creation();
    if (!server->db)
        return -1;
    server->socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server->socket < 0)
        return -1;
    server->addr.sin_family = AF_INET;
    server->addr.sin_port = htons(atoi(port_param));
    server->addr.sin_addr.s_addr = INADDR_ANY;
    server->len = sizeof(server->addr);
    if (bind(server->socket, (struct sockaddr *)&server->addr,
        server->len) < 0)
        return -1;
    if (listen(server->socket, MAX_CLIENTS) < 0)
        return -1;
    return 0;
}

void server_loop(client_sock_t *clients, server_t *server)
{
    FD_ZERO(&server->rfd);
    FD_ZERO(&server->wfd);
    FD_SET(server->socket, &server->rfd);
    for (int i = 0; clients[i].socket != 0; i++) {
        FD_SET(clients[i].socket, &server->rfd);
        FD_SET(clients[i].socket, &server->wfd);
    }
    select(FD_SETSIZE, &server->rfd, &server->wfd, NULL, NULL);
    if (FD_ISSET(server->socket, &server->rfd)) {
        new_client(clients, accept(server->socket,
        (struct sockaddr *)&server->addr, &server->len));
    }
    listen_clients(clients, server);
}

int my_teams_server(int ac, char **av)
{
    server_t server;
    client_sock_t *clients;

    if (has_param_error(ac, av))
        return 84;
    if (strcmp(av[1], "-help") == 0)
        return display_help();
    if (configure_server(&server, av[1]) < 0)
        return 84;
    clients = init_clients();
    if (!clients) {
        close(server.socket);
        return 84;
    }
    setbuf(stdout, NULL);
    while (1)
        server_loop(clients, &server);
    close(server.socket);
    return 0;
}
