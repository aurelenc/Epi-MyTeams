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

database_t *database_creation(void)
{
    database_t *database = calloc(sizeof(database_t), 1);

    if (!database) {
        perror("Database creation");
        exit (84);
    }
    database->users = llist_init();
    database->teams = llist_init();
    database->channels = llist_init();
    database->messages = llist_init();
    database->threads = llist_init();
    database->discussions = llist_init();
    if (!database->users || database->teams || database->channels ||
        database->messages || database->threads || database->discussions) {
        perror("Database creation");
        exit (84);
    }
    return (database);
}
