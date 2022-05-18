/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** discussion_search
*/

#pragma once

///
/// @brief It compares the id of a discussion with a given id
///
/// @param elem The element to compare.
/// @param search The search key.
///
/// @return A boolean value.
///
bool discussion_id_compare(const void *elem, const void *search);

///
/// @brief It compares the name of a discussion to a string
///
/// @param elem The element to compare.
/// @param search The search key.
///
/// @return A boolean value.
///
bool discussion_name_compare(const void *elem, const void *search);

///
/// @brief It compares the user_one_id of a discussion with a given id
///
/// @param elem The element to compare.
/// @param search The value to search for.
///
/// @return A boolean value.
///
bool discussion_user_one_id_compare(const void *elem, const void *search);

///
/// @brief It compares the user_two_id of a discussion with a given id
///
/// @param elem The element to compare.
/// @param search The value to search for.
///
/// @return A boolean value.
///
bool discussion_user_two_id_compare(const void *elem, const void *search);
