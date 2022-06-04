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

/// @brief Subscribe to the event of a team and its sub directories
/// (enable reception of all events from a team)
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

/// @brief Use handle the `/use` command
/// @param param The command param structure
/// @return The reply code
int command_use(TEAMS_A);

/// @brief Use in none context
/// @param param The command param structure
/// @return The reply code
int command_use_nothing(TEAMS_A);

/// @brief Use handle the `/use` command for one argument
/// @param param The command param structure
/// @return The reply code
int command_use_one_arg(TEAMS_A);

/// @brief Use handle the `/use` command for two arguments
/// @param param The command param structure
/// @return The reply code
int command_use_two_arg(TEAMS_A);

/// @brief Use handle the `/use` command for three arguments
/// @param param The command param structure
/// @return The reply code
int command_use_three_arg(TEAMS_A);

///
/// @brief If the client is not logged in, it returns an error; if the client is
/// already in a thread, it creates a reply; if the client is already in a
/// channel, it creates a thread; if the client is already in a team, it creates
/// a channel; otherwise, it creates a team
///
/// @param param The parameter object that was passed to the command.
///
/// @return The return value of the function.
////
int command_create(command_param_t *param);

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
