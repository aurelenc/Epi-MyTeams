/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** channel_searchs
*/

#include "../fields/channel.h"
#include <stdbool.h>
#include <string.h>

bool channel_id_compare(const void *elem, const void *search)
{
    const channel_t *u = (const channel_t *)elem;
    const id_t *id = (const id_t *)search;

    if (u->id == *id)
        return true;
    return false;
}


bool channel_name_compare(const void *elem, const void *search)
{
    const channel_t *u = (const channel_t *)elem;
    const char *name = (const char *)search;

    if (strcmp(u->name, name) == 0)
        return true;
    return false;
}


bool channel_team_id_compare(const void *elem, const void *search)
{
    const channel_t *u = (const channel_t *)elem;
    const id_t *id = (const id_t *)search;

    if (u->team_id == *id)
        return true;
    return false;
}
