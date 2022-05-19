/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** discussion_searchs
*/

#include "../fields/discussion.h"
#include <stdbool.h>
#include <string.h>

bool discussion_id_compare(const void *elem, const void *search)
{
    const discussion_t *u = (const discussion_t *)elem;
    const id_t *id = (const id_t *)search;

    if (u->id == *id)
        return true;
    return false;
}

bool discussion_name_compare(const void *elem, const void *search)
{
    const discussion_t *u = (const discussion_t *)elem;
    const char *name = (const char *)search;

    if (strcmp(u->name, name) == 0)
        return true;
    return false;
}

bool discussion_user_one_id_compare(const void *elem, const void *search)
{
    const discussion_t *u = (const discussion_t *)elem;
    const id_t *id = (const id_t *)search;

    if (u->user_one_id == *id)
        return true;
    return false;
}

bool discussion_user_two_id_compare(const void *elem, const void *search)
{
    const discussion_t *u = (const discussion_t *)elem;
    const id_t *id = (const id_t *)search;

    if (u->user_two_id == *id)
        return true;
    return false;
}
