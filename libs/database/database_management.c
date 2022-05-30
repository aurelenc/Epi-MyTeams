/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** database_management
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
    db->users_teams = llist_init();
    if (!db->users || !db->teams || !db->channels || !db->messages
        || !db->threads || !db->discussions || !db->users_teams) {
        perror("Database creation");
        exit (84);
    }
    return (db);
}

database_t *db_destruction(database_t *db)
{
    if (!db)
        return (0);
    if (db->users)
        db->users = llist_destruction(db->users);
    if (db->teams)
        db->teams = llist_destruction(db->teams);
    if (db->channels)
        db->channels = llist_destruction(db->channels);
    if (db->messages)
        db->messages = llist_destruction(db->messages);
    if (db->threads)
        db->threads = llist_destruction(db->threads);
    if (db->discussions)
        db->discussions = llist_destruction(db->discussions);
    if (db->users_teams)
        db->users_teams = llist_destruction(db->users_teams);
    free(db);
    return (0);
}