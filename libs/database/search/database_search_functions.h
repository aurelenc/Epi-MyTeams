/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** database_search_functions
*/

#pragma once

/*
** Users
*/

///
/// @brief It compares a user's id to a given id
///
/// @param elem The element to compare.
/// @param search The value to search for.
///
/// @return A boolean value.
///
bool user_id_compare(const void *elem, const void *search);

///
/// @brief It compares the pseudo of a user with a given pseudo
///
/// @param elem the element to compare
/// @param search the value to search for
///
/// @return A boolean value.
///
bool user_pseudo_compare(const void *elem, const void *search);

/*
** Team
*/

///
/// @brief It compares the id of a team with the id of a user
///
/// @param elem The element in the array to compare.
/// @param search The value to search for.
///
/// @return A pointer to the team_t struct that has the id that was passed in.
///
bool team_id_compare(const void *elem, const void *search);

///
/// @brief It compares the name of a team to a string
///
/// @param elem The element in the array to compare.
/// @param search The value to search for.
///
/// @return A pointer to the team_t struct.
///
bool team_name_compare(const void *elem, const void *search);

/*
** Channel
*/

///
/// @brief It compares the id of a channel with the id of a user
///
/// @param elem The element to compare.
/// @param search The search key.
///
/// @return A boolean value.
///
bool channel_id_compare(const void *elem, const void *search);

///
/// @brief It compares the name of a channel with a string
///
/// @param elem The element to compare.
/// @param search The search key.
///
/// @return A boolean value.
///
bool channel_name_compare(const void *elem, const void *search);

///
/// @brief It compares the name of a channel with a string
///
/// @param elem The element to compare.
/// @param search The search key.
///
/// @return A boolean value.
///
bool channel_team_id_compare(const void *elem, const void *search);

/*
** Message
*/

///
/// It compares the id of a message with the id of a search
///
/// @param elem The element to compare.
/// @param search The value to search for.
///
/// @return A boolean value.
///
bool msg_id_compare(const void *elem, const void *search);

///
/// It compares the user_id of a message with the user_id passed in as a
/// parameter
///
/// @param elem The element to compare.
/// @param search The value to search for.
///
/// @return A boolean value.
///
bool msg_user_id_compare(const void *elem, const void *search);

///
/// It compares the thread_id of a message with the thread_id passed in as a
/// parameter
///
/// @param elem The element to compare.
/// @param search The value to search for.
///
/// @return A boolean value.
///
bool msg_thread_id_compare(const void *elem, const void *search);

///
/// It compares the channel_id of a message with the channel_id passed in as a
/// parameter
///
/// @param elem The element to compare.
/// @param search The value to search for.
///
/// @return A boolean value.
///
bool msg_channel_id_compare(const void *elem, const void *search);

///
/// It compares the discussion_id of a message with the discussion_id passed in
/// as a parameter
///
/// @param elem The element to compare.
/// @param search The value to search for.
///
/// @return A boolean value.
///
bool msg_discussion_id_compare(const void *elem, const void *search);

/*
** Thread
*/

///
/// @brief It compares the id of a thread with the id of a thread that is being
/// searched for
///
/// @param elem The element to compare.
/// @param search The value to search for.
///
/// @return A boolean value.
///
bool thread_id_compare(const void *elem, const void *search);

///
/// @brief It compares the start_msg_id of a thread_t with an id_t
///
/// @param elem The element to compare.
/// @param search The value to search for.
///
/// @return A boolean value.
///
bool thread_start_msg_id_compare(const void *elem, const void *search);
