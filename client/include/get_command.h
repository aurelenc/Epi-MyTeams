/*
** EPITECH PROJECT, 2022
** My_Teams
** File description:
** get_command
*/

#ifndef GET_COMMAND_H_
#define GET_COMMAND_H_

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int log_client(char *command);

typedef	struct tab_command_sending_s {
  char *cmd;
  int (*function)(char *);
} tab_command_sending_t;

extern tab_command_sending_t gptrtab[];

int check_params(char *av);

int parse_command(char *input);

#endif /* !GET_COMMAND_H_ */
