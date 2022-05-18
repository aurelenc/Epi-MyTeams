/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** database_destruction
*/

#include "database.h"
#include <stdlib.h>

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
