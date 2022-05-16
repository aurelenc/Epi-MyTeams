/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** database
*/

#pragma once

#include "fields/user.h"
#include "fields/team.h"
#include "fields/channel.h"
#include "fields/message.h"
#include "fields/thread.h"
#include "fields/discussion.h"
#include "llist.h"
#include "search/database_search_functions.h"

typedef struct database_s
{
    llist_t *users;
    llist_t *teams;
    llist_t *channels;
    llist_t *messages;
    llist_t *threads;
    llist_t *discussions;
} database_t;

/**
 * @brief It creates a database
 *
 * @return A pointer to a database_t struct.
 */
database_t *db_creation(void);

/**
 * @brief It frees all the linked lists in the database
 *
 * @param database the database to destroy
 *
 * @return A pointer to a database_t struct.
 */
database_t *db_destuction(database_t *database);

/**
 * @brief Add a user to the database.
 *
 * @param db The database to add the user to.
 * @param user The user to add to the database.
 *
 * @return A boolean value.
 */
static inline bool db_add_user(database_t *db, user_t *user)
{
    return llist_append(db->users, user);
};

/**
 * @brief It searches the database for a user with the given id
 *
 * @param db The database to search in.
 * @param id The id of the user to search for.
 *
 * @return A pointer to a user_t struct.
 */
static inline user_t *db_search_user_by_id(database_t *db, const id_t id)
{
    return llist_search(db->users, &user_id_compare, id);
};

/**
 * @brief It searches the database for a user with the given pseudo
 *
 * @param db the database
 * @param pseudo the pseudo of the user to search for
 *
 * @return A pointer to the user_t struct.
 */
static inline user_t *db_search_user_by_pseudo(database_t *db, const char *pseudo)
{
    return llist_search(db->users, &user_pseudo_compare, pseudo);
};

/**
 * @brief It deletes a user, with the given id, in the database
 *
 * @param db The database to search in.
 * @param id The id of the user to delete.
 *
 * @return A boolean value.
 */
static inline bool db_delete_user_by_id(database_t *db, const id_t id)
{
    return llist_delif(db->users, &user_id_compare, id);
}

/**
 * @brief It deletes a user, with the given pseudo, in the database
 *
 * @param db the database.
 * @param pseudo the pseudo of the user to delete.
 *
 * @return A boolean value.
 */
static inline bool db_search_user_by_pseudo(database_t *db, const char *pseudo)
{
    return llist_delif(db->users, &user_pseudo_compare, pseudo);
}
