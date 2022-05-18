/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** thread
*/

#include "thread.h"
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>


thread_t *thread_init(id_t id, id_t start_msg_id)
{
    thread_t *thread = calloc(sizeof(thread_t), 1);

    if (!thread) {
        perror("Thread creation");
        exit (84);
    }
    thread->id = id;
    thread->start_msg_id = start_msg_id;
    return (thread);
}

void thread_destruction(thread_t *thread)
{
    if (!thread)
        return;
    free(thread);
}
