/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** database_user
*/

#include "database.h"

bool db_add_user(database_t *db, user_t *user)
{
    return llist_append(db->users, user);
}
