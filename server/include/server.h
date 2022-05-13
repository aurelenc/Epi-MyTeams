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

#define MAX_BUFF_SIZE 2048
#define MAX_USER_SIZE 256
#define MAX_CLIENTS 20
#define MAX_ARGS_NB 1
#define MAX_PARAMS_NB MAX_ARGS_NB + 1

typedef struct client_sock_s {
    int socket;
    bool is_logged;
    bool is_passive;
    int transfer_socket;
    char *rbuf;
    char *wbuf;
    char *user;
    char *pass;
    char *path;
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
    char *default_path;
} server_t;

typedef struct params_s {
    char **array;
    int nb;
} params_t;

typedef struct command_s {
    char *cmd;
    int required_params_nb;
    int optional_params_nb;
    int (*func)(client_sock_t *, int, server_t *, params_t);
    bool auth_required;
} command_t;

extern const command_t commands[];
