/*
** EPITECH PROJECT, 2022
** Epi-MyTeams
** File description:
** commands
*/

#ifndef COMMANDS_H_
#define COMMANDS_H_

#include "server.h"

int command_login(client_sock_t *clients, int id, server_t *srv, params_t arg);
int command_logout(client_sock_t *clients, int id, server_t *srv, params_t arg);

#endif /* !COMMANDS_H_ */
