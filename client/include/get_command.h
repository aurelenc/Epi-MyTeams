/*
** EPITECH PROJECT, 2022
** My_Teams
** File description:
** get_command
*/

#ifndef GET_COMMAND_H_
#define GET_COMMAND_H_

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

/// Manage commands for client
///
/// /get_commands
int unsubscribe_teams(char *av, int socket);
int subscribe_teams(char *av, int socket);
int send_message(char *av, int socket);
int logout_client(char *av, int socket);
int login_client(char *av, int socket);
int use(char *av, int socket);
int info(char *av, int socket);
int list(char *av, int socket);
int create(char *av, int socket);
int messages(char *av, int socket);
int user(char *av, int socket);
int users(char *av, int socket);

typedef	struct tab_command_sending_s {
  char *cmd;
  int (*function)(char *, int);
} tab_command_sending_t;

extern tab_command_sending_t gptrtab[];

bool make_command_rfc_compatible(char *dest, char *command, char *av);
char *manage_params(char *av);
int check_params(char *av);

char **parse_response(char *response, int nb_params);

char **send_command(char *av, char **tab_response, char *command, int socket);

int parse_command(char *input, int socket);

#endif /* !GET_COMMAND_H_ */
