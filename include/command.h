/*
** EPITECH PROJECT, 2022
** Project
** File description:
** command
*/

#ifndef COMMAND_H_
#define COMMAND_H_

#include <stdlib.h>

typedef	struct tab_command_s {
  char* cmd;
  void (*function)(char *);
} tab_command_t;

extern tab_command_t gptrtab[22];

#endif /* !COMMAND_H_ */
