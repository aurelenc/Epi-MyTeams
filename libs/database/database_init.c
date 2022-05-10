/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** database_init
*/

#include "database.h"
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

database_t *db_creation(void)
{
    database_t *db = calloc(sizeof(database_t), 1);

    if (!db) {
        perror("Database creation");
        exit (84);
    }
    db->users = llist_init();
    db->teams = llist_init();
    db->channels = llist_init();
    db->messages = llist_init();
    db->threads = llist_init();
    db->discussions = llist_init();
    if (!db->users || db->teams || db->channels ||
        db->messages || db->threads || db->discussions) {
        perror("Database creation");
        exit (84);
    }
    return (db);
}
