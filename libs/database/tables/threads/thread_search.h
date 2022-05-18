/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** thread_search
*/

#pragma once

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
