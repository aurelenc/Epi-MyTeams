/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** thread_searchs
*/

#include "../fields/thread.h"
#include <stdbool.h>
#include <string.h>

bool thread_id_compare(const void *elem, const void *search)
{
    const thread_t *u = (const thread_t *)elem;
    const id_t *id = (const id_t *)search;

    if (u->id == *id)
        return true;
    return false;
}

bool thread_start_msg_id_compare(const void *elem, const void *search)
{
    const thread_t *u = (const thread_t *)elem;
    const id_t *id = (const id_t *)search;

    if (u->start_msg_id == *id)
        return true;
    return false;
}
