/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** thread_searchs
*/

#include "thread.h"
#include <stdbool.h>
#include <string.h>

bool thread_id_compare(const void *elem, const void *search)
{
    const thread_t *thread = (const thread_t *)elem;
    const id_t *id = (const id_t *)search;

    if (thread->id == *id)
        return true;
    return false;
}

bool thread_uuid_compare(const void *elem, const void *search)
{
    const thread_t *thread = (const thread_t *)elem;
    const char *uuid = (const char *)search;

    if (strcmp(thread->uuid, uuid) == 0)
        return true;
    return false;
}

bool thread_title_compare(const void *elem, const void *search)
{
    const thread_t *thread = (const thread_t *)elem;
    const char *title = (const char *)search;

    if (strcmp(thread->title, title) == 0)
        return true;
    return false;
}

bool thread_channel_id_compare(const void *elem, const void *search)
{
    const thread_t *thread = (const thread_t *)elem;
    const id_t *id = (const id_t *)search;

    if (thread->channel_id == *id)
        return true;
    return false;
}
