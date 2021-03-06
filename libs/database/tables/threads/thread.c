/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** thread
*/

#include "thread.h"
#include "tables/uuid_gen.h"
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>


thread_t *thread_init(char *title, char *body, id_t user_id, id_t channel_id)
{
    thread_t *thread = calloc(sizeof(thread_t), 1);

    if (!thread) {
        perror("Thread creation");
        exit(84);
    }
    thread->timestamp = time(NULL);
    thread->id = 0;
    thread->title = title;
    thread->body = body;
    thread->uuid = uuid_gen();
    if (!thread->uuid) {
        perror("Thread creation");
        exit(84);
    }
    thread->user_id = user_id;
    thread->channel_id = channel_id;
    return (thread);
}

void thread_destruction(thread_t *thread)
{
    if (!thread)
        return;
    free(thread);
}
