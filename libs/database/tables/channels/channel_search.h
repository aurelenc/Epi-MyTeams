/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** channel_search
*/

#pragma once

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
/// @brief It compares the UUID of a channel with a given UUID
///
/// @param elem The element in the list to compare.
/// @param search The search key.
///
/// @return A boolean value.
///
bool channel_uuid_compare(const void *elem, const void *search);

///
/// @brief It compares the name of a channel with a given name
///
/// @param elem The element in the list to compare.
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
