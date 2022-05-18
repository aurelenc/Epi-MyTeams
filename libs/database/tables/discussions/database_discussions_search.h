/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** database_discussions_search
*/

#pragma once

#include "discussion.h"
#include "database.h"
#include "discussion_search.h"

///
/// @brief It searches the database for a discussion with the given id
///
/// @param db The database to search in.
/// @param id The id of the discussion to search for.
///
/// @return A pointer to a discussion_t struct.
///
static inline discussion_t *db_search_discussion_by_id(database_t *db,
const id_t id)
{
    return (discussion_t *)llist_search(db->discussions,
    &discussion_id_compare, &id);
};

///
/// @brief It searches the database for a discussion with the given name
///
/// @param db The database to search in.
/// @param name The name of the discussion to search for.
///
/// @return A pointer to a discussion_t struct.
///
static inline discussion_t *db_search_discussion_by_name(database_t *db,
const char *name)
{
    return (discussion_t *)llist_search(db->discussions,
    &discussion_name_compare, name);
};

///
/// @brief It searches the database's
///discussion list for a discussion with the given user one ID
///
/// @param db The database to search in.
/// @param user_one_id The user one ID to search for.
///
/// @return A pointer to a discussion_t struct.
///
static inline discussion_t *db_search_discussion_by_user_one_id(database_t *db,
const id_t user_one_id)
{
    return (discussion_t *)llist_search(db->discussions,
    &discussion_user_one_id_compare, &user_one_id);
};

///
/// @brief It searches the database's
/// discussion list for a discussion with the given user two ID
///
/// @param db The database to search in.
/// @param user_two_id The user two ID to search for.
///
/// @return A pointer to a discussion_t struct.
///
static inline discussion_t *db_search_discussion_by_user_two_id(database_t *db,
const id_t user_two_id)
{
    return (discussion_t *)llist_search(db->discussions,
    &discussion_user_two_id_compare, &user_two_id);
};
