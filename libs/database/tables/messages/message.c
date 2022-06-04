/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** message
*/

#include "message.h"
#include "tables/uuid_gen.h"
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

msg_t *msg_init(const char *content, id_t user_id, int *relation)
{
    msg_t *msg = calloc(sizeof(msg_t), 1);

    if (!msg)
        exit(84);
    msg->id = 0;
    msg->timestamp = time(NULL);
    msg->user_id = user_id;
    msg->thread_id = relation[0];
    msg->discussion_id = relation[1];
    msg->uuid = uuid_gen();
    msg->content = strdup(content);
    if (!msg->content || !msg->uuid)
        exit(84);
    return (msg);
}

void msg_destruction(msg_t *msg)
{
    if (!msg)
        return;
    free(msg->content);
    free(msg);
}
