/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** user_team_search
*/

#include "tables/users_x_teams.h"
#include <stdbool.h>

bool user_team_user_id_compare(const void *elem, const void *search)
{
    const id_pair_t *pair = (const id_pair_t *)elem;
    const id_t *id = (const id_t *)search;

    if (pair->user_id == *id)
        return true;
    return false;
}

bool user_team_team_id_compare(const void *elem, const void *search)
{
    const id_pair_t *pair = (const id_pair_t *)elem;
    const id_t *id = (const id_t *)search;

    if (pair->team_id == *id)
        return true;
    return false;
}

bool user_team_pair_compare(const void *elem, const void *search)
{
    const id_pair_t *pair = (const id_pair_t *)elem;
    const id_pair_t *s_pair = (const id_pair_t *)search;

    if (pair->team_id == s_pair->team_id && pair->user_id == s_pair->user_id)
        return true;
    return false;
}
