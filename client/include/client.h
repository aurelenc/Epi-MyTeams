/*
** EPITECH PROJECT, 2022
** Epi-MyTeams
** File description:
** client
*/

#pragma once

#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 4096
#define PORT 8080
#define SA struct sockaddr

int my_teams_client(int ac, char **av);

/// Signals
void set_sigint_handler(void);

typedef struct client_s {
    bool is_in_teams;
    bool is_in_channel;
    bool is_in_thread;
    bool is_connected;
    fd_set rfd;
    fd_set wfd;
    int socket;
    struct sockaddr_in servaddr;
} client_t;

void create_client(client_t *client, char **av);
