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
