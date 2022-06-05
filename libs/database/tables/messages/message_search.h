/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** message_search
*/

#pragma once

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
/// It compares the uuid of a message with the uuid of a search
///
/// @param elem The element to compare.
/// @param search The value to search for.
///
/// @return A boolean value.
///
bool msg_uuid_compare(const void *elem, const void *search);

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
/// It compares the discussion_id of a message with the discussion_id passed
/// in as a parameter
///
/// @param elem The element to compare.
/// @param search The value to search for.
///
/// @return A boolean value.
///
bool msg_discussion_id_compare(const void *elem, const void *search);
