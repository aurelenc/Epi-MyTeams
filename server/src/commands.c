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
    {"USRS", 0, 0, &command_users, true},
    {"USR", 1, 0, &command_user, true},
    {"SEND", 2, 0, &command_send, true},
    {"MSG", 1, 0, &command_messages, true},
    {"SUB", 1, 0, &command_subscribe, true},
    {"SUBT", 1, 0, &command_subscribed_teams, true},
    {"SUBU", 1, 0, &command_subscribed_users, true},
    {"USUB", 1, 0, &command_unsubscribe, true},
    {"USE", 0, 3, &command_use, true},
    {"CRTE", 1, 0, &command_create_team, true},
    {"CRCH", 2, 0, &command_create_channel, true},
    {"CRTH", 2, 0, &command_create_thread, true},
    {"CRTE", 2, 0, &command_create_reply, true},
    {"LSTE", 1, 0, &command_list_teams, true},
    {"LSCH", 1, 0, &command_list_channels, true},
    {"LSTH", 1, 0, &command_list_threads, true},
    {"LSTE", 1, 0, &command_list_replies, true},
    {"IFTE", 1, 0, &command_info_team, true},
    {"IFCH", 1, 0, &command_info_channel, true},
    {"IFTH", 1, 0, &command_info_thread, true},
    {"IFTH", 1, 0, &command_info_user, true},
    {"NULL", 0, 0, NULL, false}
};
