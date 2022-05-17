/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** message_search
*/

#include "fields/message.h"
#include <stdbool.h>

bool msg_id_compare(const void *elem, const void *search)
{
    const msg_t *msg = (const msg_t *)elem;
    const id_t *id = (const id_t *)search;

    if (msg->id == *id)
        return true;
    return false;
}

bool msg_user_id_compare(const void *elem, const void *search)
{
    const msg_t *msg = (const msg_t *)elem;
    const id_t *id = (const id_t *)search;

    if (msg->user_id == *id)
        return true;
    return false;
}

bool msg_thread_id_compare(const void *elem, const void *search)
{
    const msg_t *msg = (const msg_t *)elem;
    const id_t *id = (const id_t *)search;

    if (msg->thread_id == *id)
        return true;
    return false;
}

bool msg_channel_id_compare(const void *elem, const void *search)
{
    const msg_t *msg = (const msg_t *)elem;
    const id_t *id = (const id_t *)search;

    if (msg->channel_id == *id)
        return true;
    return false;
}

bool msg_discussion_id_compare(const void *elem, const void *search)
{
    const msg_t *msg = (const msg_t *)elem;
    const id_t *id = (const id_t *)search;

    if (msg->discussion_id == *id)
        return true;
    return false;
}
