/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** user_searchs
*/

#include "user.h"
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

bool user_uuid_compare(const void *elem, const void *search)
{
    const user_t *user = (const user_t *)elem;
    const char *uuid = (const char *)search;

    if (strcmp(user->uuid, uuid) == 0)
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

bool user_id_array_compare(const void *elem, const void *search)
{
    const user_t *user = (const user_t *)elem;
    const id_t *ids = (const id_t *)search;

    for (int i = 0; ids[i] != 0; i++)
        if (user->id == ids[i])
            return true;
    return false;
}
