/*
** EPITECH PROJECT, 2022
** Epi-MyTeams
** File description:
** server
*/

#pragma once

#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <stdbool.h>
#include "database.h"

#define MAX_BUFF_SIZE 4096
#define CBUFF_SIZE (int)4e+6
#define MAX_USER_SIZE 256
#define MAX_CLIENTS 20
#define MAX_ARGS_NB 1
#define MAX_PARAMS_NB MAX_ARGS_NB + 1
#define UUID_SIZE 37

typedef struct client_sock_s {
    int socket;
    char *rbuf;
    char *wbuf;
    char *user;
    int team_id;
    int channel_id;
    int thread_id;
} client_sock_t;

typedef struct client_id_s {
    client_sock_t *clients;
    int id;
} client_id_t;

typedef struct server_s {
    int socket;
    fd_set rfd;
    fd_set wfd;
    struct sockaddr_in addr;
    socklen_t len;
    database_t *db;
} server_t;

typedef struct params_s {
    char **array;
    int nb;
} params_t;

typedef struct command_param_s {
    client_sock_t *clients;
    int id;
    server_t *srv;
    params_t arg;
} command_param_t;

typedef struct command_s {
    char *cmd;
    int required_params_nb;
    int optional_params_nb;
    int (*func)(command_param_t *);
    bool auth_required;
} command_t;

extern const command_t commands[];

/// Launch
bool has_param_error(int ac, char **av);
int display_help(void);

/// Clients
void new_client(client_sock_t *clients, int client_socket);
void remove_client(client_sock_t *clients, int remove_index);
void listen_clients(client_sock_t *clients, server_t *server);
void write_client_buff(client_sock_t *clients, int i, char *message);
void handle_input(client_sock_t *clients, int id, server_t *server);
