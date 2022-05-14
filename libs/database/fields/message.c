/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** message
*/

#include "message.h"
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

msg_t *msg_init(id_t id, const char *content, id_t user_id, int relation[3])
{
    msg_t *msg = calloc(sizeof(msg_t), 1);

    if (!msg) {
        perror("Message creation");
        exit (84);
    }
    msg->id = id;
    msg->content = strdup(content);
    msg->thread_id = relation[0];
    msg->channel_id = relation[1];
    msg->discussion_id = relation[2];
    if (!msg->content) {
        perror("Message creation");
        exit (84);
    }
    return (msg);
}


void msg_destruction(msg_t *msg)
{
    if (!msg)
        return;
    free(msg->content);
}
