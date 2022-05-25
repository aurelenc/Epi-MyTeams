/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** user_team_search
*/

#pragma once


///
/// @brief It compares the user_id of a id_pair_t struct with a given id_t.
///teamteam
/// @param elem The element to compare.
/// @param search The search key.
///
/// @return A boolean value.
///
bool user_team_user_id_compare(const void *elem, const void *search);

///
/// @brief It compares the team_id of a id_pair_t struct with a given id_t.
///
/// @param elem The element to compare.
/// @param search The search key.
///
/// @return A pointer to the first element in the array that matches the search
/// criteria.
///
bool user_team_team_id_compare(const void *elem, const void *search);

///
/// @brief It compares two id_pair_t structs to see if they are equal
///
/// @param elem The element to compare.
/// @param search The search key.
///
/// @return A boolean value.
///
bool user_team_pair_compare(const void *elem, const void *search);
