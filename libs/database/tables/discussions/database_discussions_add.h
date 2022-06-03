/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** database_discussions_add
*/

#pragma once

#include "discussion.h"
#include "database.h"

///
/// @brief It adds a discussion to the database
///
/// @param db The database object
/// @param discussion The discussion to add to the database.
///
/// @return A boolean value.
///
static inline bool db_add_discussion(database_t *db, discussion_t *discussion)
{
    discussion->id = llist_get_size(db->discussions) + 1;
    return llist_append(db->discussions, discussion);
};
