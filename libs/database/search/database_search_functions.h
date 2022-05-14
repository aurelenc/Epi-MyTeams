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

/**
 * @brief It compares a user's id to a given id
 *
 * @param elem The element to compare.
 * @param search The value to search for.
 *
 * @return A boolean value.
 */
bool user_id_compare(const void *elem, const void *search);

/**
 * @brief It compares the pseudo of a user with a given pseudo
 *
 * @param elem the element to compare
 * @param search the value to search for
 *
 * @return A boolean value.
 */
bool user_pseudo_compare(const void *elem, const void *search);
