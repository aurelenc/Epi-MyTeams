/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** database
*/

#pragma once

#include "user.h"
#include "team.h"
#include "channel.h"
#include "message.h"
#include "thread.h"
#include "discussion.h"
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
database_t *database_creation(void);

/**
 * @brief It frees all the linked lists in the database
 *
 * @param database the database to destroy
 *
 * @return A pointer to a database_t struct.
 */
database_t *database_destuction(database_t *database)
