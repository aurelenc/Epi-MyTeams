/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** database_threads_multiple_search
*/

#include "thread.h"
#include "database.h"
#include "database_management.h"
#include "thread_search.h"

database_t *db_multiple_search_threads_by_channel_id(database_t *db,
const id_t channel_id)
{
    database_t *found = db_creation();

    if (!found)
        return (0);
    llist_destruction(found->threads);
    found->threads = llist_multiple_search(db->threads, &thread_channel_id_compare, &channel_id);
    return found;
}
