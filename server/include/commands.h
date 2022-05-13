/*
** EPITECH PROJECT, 2022
** Epi-MyTeams
** File description:
** commands
*/

#ifndef COMMANDS_H_
#define COMMANDS_H_

#include "server.h"

int command_login(command_param_t *param);
int command_logout(command_param_t *param);
int command_users(command_param_t *param);
int command_user(command_param_t *param);
int command_send(command_param_t *param);
int command_messages(command_param_t *param);
int command_subscribe(command_param_t *param);
int command_subscribed_teams(command_param_t *param);
int command_subscribed_users(command_param_t *param);
int command_unsubscribe(command_param_t *param);
int command_use_team(command_param_t *param);
int command_use_channel(command_param_t *param);
int command_use_thread(command_param_t *param);
int command_create_team(command_param_t *param);
int command_create_channel(command_param_t *param);
int command_create_thread(command_param_t *param);
int command_list_teams(command_param_t *param);
int command_list_channels(command_param_t *param);
int command_list_threads(command_param_t *param);
int command_info_team(command_param_t *param);
int command_info_channel(command_param_t *param);
int command_info_thread(command_param_t *param);

#endif /* !COMMANDS_H_ */
