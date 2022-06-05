/*
** EPITECH PROJECT, 2022
** Epi-MyFTP
** File description:
** commands
*/

#include <unistd.h>
#include "commands.h"

const command_t commands[] = {
    {"\"LOGI\"", 1, 0, &command_login, false},
    {"\"LOGO\"", 0, 0, &command_logout, true},
    {"\"USRS\"", 0, 0, &command_users, true},
    {"\"USR\"", 1, 0, &command_user, true},
    {"\"SEND\"", 2, 0, &command_send, true},
    {"\"MSG\"", 1, 0, &command_messages, true},
    {"\"SUB\"", 1, 0, &command_subscribe, true},
    {"\"SUBD\"", 1, 0, &command_subscribed, true},
    {"\"USUB\"", 1, 0, &command_unsubscribe, true},
    {"\"USE\"", 0, 3, &command_use, true},
    {"\"CREA\"", 1, 0, &command_create, true},
    {"\"LIST\"", 1, 0, &command_list, true},
    {"\"INFO\"", 1, 0, &command_info, true},
    {"NULL", 0, 0, NULL, false}
};
