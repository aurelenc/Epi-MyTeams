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
int command_login(TEAMS_A);

/// @brief Disconnect the client from the server
/// @param param The command param structure
/// @return The reply code
int command_logout(TEAMS_A);

/// @brief Get the list of all users that exist on the domain
/// @param param The command param structure
/// @return The reply code
int command_users(TEAMS_A);

/// @brief Get information about a user
/// @param param The command param structure
/// @return The reply code
int command_user(TEAMS_A);

/// @brief Send a message to a user
/// @param param The command param structure
/// @return The reply code
int command_send(TEAMS_A);

/// @brief List all messages exchange with an user
/// @param param The command param structure
/// @return The reply code
int command_messages(TEAMS_A);

/// @brief Subscribe to the event of a team and its sub directories (enable reception of all events from a team)
/// @param param The command param structure
/// @return The reply code
int command_subscribe(TEAMS_A);

/// @brief List all subscribed teams
/// @param param The command param structure
/// @return The reply code
int command_subscribed_teams(TEAMS_A);

/// @brief List all users subscribed to a team
/// @param param The command param structure
/// @return The reply code
int command_subscribed_users(TEAMS_A);

/// @brief Unsubscribe from a team
/// @param param The command param structure
/// @return The reply code
int command_unsubscribe(TEAMS_A);

/// @brief Use specify a context team
/// @param param The command param structure
/// @return The reply code
int command_use_team(TEAMS_A);

/// @brief Use specify a context channel
/// @param param The command param structure
/// @return The reply code
int command_use_channel(TEAMS_A);

/// @brief Use specify a context thread
/// @param param The command param structure
/// @return The reply code
int command_use_thread(TEAMS_A);

/// @brief Create a new team
/// @param param The command param structure
/// @return The reply code
int command_create_team(TEAMS_A);

/// @brief Create a new channel
/// @param param The command param structure
/// @return The reply code
int command_create_channel(TEAMS_A);

/// @brief Create a new thread
/// @param param The command param structure
/// @return The reply code
int command_create_thread(TEAMS_A);

/// @brief Create a new reply
/// @param param The command param structure
/// @return The reply code
int command_create_reply(TEAMS_A);

/// @brief List all existing teams
/// @param param The command param structure
/// @return The reply code
int command_list_teams(TEAMS_A);

/// @brief List all existing channels
/// @param param The command param structure
/// @return The reply code
int command_list_channels(TEAMS_A);

/// @brief List all existing threads
/// @param param The command param structure
/// @return The reply code
int command_list_threads(TEAMS_A);

/// @brief List all existing replies
/// @param param The command param structure
/// @return The reply code
int command_list_replies(TEAMS_A);

/// @brief Display currently selected team infos
/// @param param The command param structure
/// @return The reply code
int command_info_team(TEAMS_A);

/// @brief Display currently selected channel infos
/// @param param The command param structure
/// @return The reply code
int command_info_channel(TEAMS_A);

/// @brief Display currently selected thread infos
/// @param param The command param structure
/// @return The reply code
int command_info_thread(TEAMS_A);

/// @brief Display currently logged user infos
/// @param param The command param structure
/// @return The reply code
int command_info_user(TEAMS_A);


#endif /* !COMMANDS_H_ */
