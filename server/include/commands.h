/*
** EPITECH PROJECT, 2022
** Epi-MyTeams
** File description:
** commands
*/

#ifndef COMMANDS_H_
#define COMMANDS_H_

#include "server.h"

/// @brief Set the user_name used by client
/// @param param The command param structure
/// @return The reply code
int command_login(command_param_t *param);

/// @brief Disconnect the client from the server
/// @param param The command param structure
/// @return The reply code
int command_logout(command_param_t *param);

/// @brief Get the list of all users that exist on the domain
/// @param param The command param structure
/// @return The reply code
int command_users(command_param_t *param);

/// @brief Get information about a user
/// @param param The command param structure
/// @return The reply code
int command_user(command_param_t *param);

/// @brief Send a message to a user
/// @param param The command param structure
/// @return The reply code
int command_send(command_param_t *param);

/// @brief List all messages exchange with an user
/// @param param The command param structure
/// @return The reply code
int command_messages(command_param_t *param);

/// @brief Subscribe to the event of a team and its sub directories (enable reception of all events from a team)
/// @param param The command param structure
/// @return The reply code
int command_subscribe(command_param_t *param);

/// @brief List all subscribed teams
/// @param param The command param structure
/// @return The reply code
int command_subscribed_teams(command_param_t *param);

/// @brief List all users subscribed to a team
/// @param param The command param structure
/// @return The reply code
int command_subscribed_users(command_param_t *param);

/// @brief Unsubscribe from a team
/// @param param The command param structure
/// @return The reply code
int command_unsubscribe(command_param_t *param);

/// @brief Use specify a context team
/// @param param The command param structure
/// @return The reply code
int command_use_team(command_param_t *param);

/// @brief Use specify a context channel
/// @param param The command param structure
/// @return The reply code
int command_use_channel(command_param_t *param);

/// @brief Use specify a context thread
/// @param param The command param structure
/// @return The reply code
int command_use_thread(command_param_t *param);

/// @brief Create a new reply
/// @param param The command param structure
/// @return The reply code
int command_create_reply(command_param_t *param);

/// @brief Create a new team
/// @param param The command param structure
/// @return The reply code
int command_create_team(command_param_t *param);

/// @brief Create a new channel
/// @param param The command param structure
/// @return The reply code
int command_create_channel(command_param_t *param);

/// @brief Create a new thread
/// @param param The command param structure
/// @return The reply code
int command_create_thread(command_param_t *param);

/// @brief List all existing replies
/// @param param The command param structure
/// @return The reply code
int command_list_teams(command_param_t *param);

/// @brief List all existing teams
/// @param param The command param structure
/// @return The reply code
int command_list_teams(command_param_t *param);

/// @brief List all existing channels
/// @param param The command param structure
/// @return The reply code
int command_list_channels(command_param_t *param);

/// @brief List all existing threads
/// @param param The command param structure
/// @return The reply code
int command_list_threads(command_param_t *param);

/// @brief Display currently logged user infos
/// @param param The command param structure
/// @return The reply code
int command_info_user(command_param_t *param);

/// @brief Display currently selected team infos
/// @param param The command param structure
/// @return The reply code
int command_info_team(command_param_t *param);

/// @brief Display currently selected channel infos
/// @param param The command param structure
/// @return The reply code
int command_info_channel(command_param_t *param);

/// @brief Display currently selected thread infos
/// @param param The command param structure
/// @return The reply code
int command_info_thread(command_param_t *param);


#endif /* !COMMANDS_H_ */
