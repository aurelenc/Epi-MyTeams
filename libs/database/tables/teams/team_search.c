/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** team_searchs
*/

#include "team.h"
#include <stdbool.h>
#include <string.h>

bool team_id_compare(const void *elem, const void *search)
{
    const team_t *team = (const team_t *)elem;
    const id_t *id = (const id_t *)search;

    if (team->id == *id)
        return true;
    return false;
}

bool team_uuid_compare(const void *elem, const void *search)
{
    const team_t *team = (const team_t *)elem;
    const char *uuid = (const char *)search;

    if (strcmp(team->uuid, uuid) == 0)
        return true;
    return false;
}

bool team_id_array_compare(const void *elem, const void *search)
{
    const team_t *team = (const team_t *)elem;
    const id_t *ids = (const id_t *)search;

    for (int i = 0; ids[i] != 0; i++)
        if (team->id == ids[i])
            return true;
    return false;
}
