/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** database_destruction
*/

#include "database.h"
#include <stdlib.h>

database_t *db_destuction(database_t *database)
{
    if (!database)
        return (0);
    if (database->users)
        database->users = llist_destruction(database->users);
    if (database->teams)
        database->teams = llist_destruction(database->teams);
    if (database->channels)
        database->channels = llist_destruction(database->channels);
    if (database->messages)
        database->messages = llist_destruction(database->messages);
    if (database->threads)
        database->threads = llist_destruction(database->threads);
    if (database->discussions)
        database->discussions = llist_destruction(database->discussions);
    free(database);
    return (0);
}
