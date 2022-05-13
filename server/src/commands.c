/*
** EPITECH PROJECT, 2022
** Epi-MyFTP
** File description:
** commands
*/

#include <unistd.h>
#include "commands.h"

const command_t commands[] = {
    {"LOGI", 1, 0, &command_login, false},
    {"LOGO", 0, 0, &command_logout, true},
    {"NULL", 0, 0, NULL, false}
};
