/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** team_search
*/

#pragma once

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
/// @brief It compares the uuid of a team to a string
///
/// @param elem The element in the array to compare.
/// @param search The value to search for.
///
/// @return A pointer to the team_t struct.
///
bool team_uuid_compare(const void *elem, const void *search);

///
/// @brief It compares the name of a team to a string
///
/// @param elem The element in the array to compare.
/// @param search The value to search for.
///
/// @return A pointer to the team_t struct.
///
bool team_name_compare(const void *elem, const void *search);
