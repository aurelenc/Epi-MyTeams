/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** database_discussions_deletion
*/

#pragma once

#include "discussion.h"
#include "database.h"
#include "discussion_search.h"

///
/// @brief It deletes a discussion from the database by its id
///
/// @param db The database to delete the discussion from.
/// @param id The id of the discussion to delete.
///
/// @return A boolean value.
///
static inline bool db_delete_discussion_by_id(database_t *db, const id_t id)
{
    return llist_delif(db->discussions, &discussion_id_compare, &id);
};

///
/// @brief It deletes a discussion from the database by uuid
///
/// @param db The database to delete the discussion from.
/// @param uuid The uuid of the discussion to delete.
///
/// @return A boolean value.
///
static inline bool db_delete_discussion_by_uuid(database_t *db,
const char *uuid)
{
    return llist_delif(db->discussions, &discussion_uuid_compare, uuid);
};

///
/// @brief It deletes a discussion from the database if it has the same user one
/// id as the one passed in
///
/// @param db The database to delete the discussion from.
/// @param user_one_id The id of the user one to delete the discussion of.
///
/// @return A boolean value.
///
static inline bool db_delete_discussion_by_user_one_id(database_t *db,
const id_t user_one_id)
{
    return llist_delif(db->discussions, &discussion_user_one_id_compare,
    &user_one_id);
};

///
/// @brief It deletes a discussion from the database if it has the same user two
/// id as the two passed in
///
/// @param db The database to delete the discussion from.
/// @param user_two_id The id of the user two to delete the discussion of.
///
/// @return A boolean value.
///
static inline bool db_delete_discussion_by_user_two_id(database_t *db,
const id_t user_two_id)
{
    return llist_delif(db->discussions, &discussion_user_two_id_compare,
    &user_two_id);
};
