/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** user_searchs
*/

#include "fields/user.h"
#include <stdbool.h>
#include <string.h>

bool user_id_compare(const void *elem, const void *search)
{
    const user_t *user = (const user_t *)elem;
    const id_t *id = (const id_t *)search;

    if (user->id == *id)
        return true;
    return false;
}

bool user_pseudo_compare(const void *elem, const void *search)
{
    const user_t *user = (const user_t *)elem;
    const char *pseudo = (const char *)search;

    if (strcmp(user->pseudo, pseudo) == 0)
        return true;
    return false;
}
