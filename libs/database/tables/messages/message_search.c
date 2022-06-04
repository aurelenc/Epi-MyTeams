/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** message_search
*/

#include "message.h"
#include <stdbool.h>
#include <string.h>

bool msg_id_compare(const void *elem, const void *search)
{
    const msg_t *msg = (const msg_t *)elem;
    const id_t *id = (const id_t *)search;

    if (msg->id == *id)
        return true;
    return false;
}

bool msg_uuid_compare(const void *elem, const void *search)
{
    const msg_t *msg = (const msg_t *)elem;
    const char *uuid = (const char *)search;

    if (strcmp(msg->uuid, uuid) == 0)
        return true;
    return false;
}
