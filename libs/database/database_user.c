/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** database_user
*/

#include "database.h"
#include "search/database_search_functions.h"

bool db_add_user(database_t *db, user_t *user)
{
    return llist_append(db->users, user);
}

user_t *db_search_user_by_id(database_t *db, const id_t id)
{
    return llist_search(db->users, &user_id_compare, id);
}

user_t *db_search_user_by_pseudo(database_t *db, const char *pseudo)
{
    return llist_search(db->users, &user_pseudo_compare, pseudo);
}
