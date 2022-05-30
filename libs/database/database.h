/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** database
*/

#pragma once

#include "llist.h"

typedef struct database_s
{
    llist_t *users;
    llist_t *teams;
    llist_t *channels;
    llist_t *messages;
    llist_t *threads;
    llist_t *discussions;
    llist_t *users_teams;
} database_t;
