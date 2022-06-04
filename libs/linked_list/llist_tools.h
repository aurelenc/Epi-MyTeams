/*
** EPITECH PROJECT, 2022
** Linked List Library
** File description:
** llist_tools
*/

#pragma once

#include "llist.h"

///
/// @brief It takes a list and a position, and returns the node at that
/// position
///
/// @param list The list to take the node from.
/// @param position The position of the node to take.
///
/// @return A pointer to the node at the given position.
///
node_t *llist_take_node_at_position(llist_t *list, unsigned int position);
