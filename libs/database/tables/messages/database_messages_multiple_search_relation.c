/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** database_messages_multiple_search_relation
*/

#include "message.h"
#include "database.h"
#include "database_management.h"
#include "message_search.h"

database_t *db_multiple_search_msg_by_user_id(database_t *db,
const id_t user_id)
{
    database_t *found = db_creation();

    if (!found)
        return (0);
    llist_destruction(found->messages);
    found->messages = llist_multiple_search(db->messages, &msg_user_id_compare, &user_id);
    return found;
};

database_t *db_multiple_search_msg_by_thread_id(database_t *db,
const id_t thread_id)
{
    database_t *found = db_creation();

    if (!found)
        return (0);
    llist_destruction(found->messages);
    found->messages = llist_multiple_search(db->messages, &msg_thread_id_compare,
    &thread_id);
    return (found);
};

database_t *db_multiple_search_msg_by_discussion_id(database_t *db,
const id_t discu_id)
{
    database_t *found = db_creation();

    if (!found)
        return (0);
    llist_destruction(found->messages);
    found->messages = llist_multiple_search(db->messages, &msg_discussion_id_compare,
    &discu_id);
    return (found);
};
