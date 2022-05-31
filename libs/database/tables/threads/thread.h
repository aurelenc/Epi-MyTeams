/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** thread
*/

#pragma once

#include <time.h>

typedef unsigned int id_t;

typedef struct thread_s {
    id_t id;
    char *uuid;
    char *title;
    char *body;
    id_t channel_id;
    time_t timestamp;
} thread_t;

///
/// @brief It creates a thread_t structure and initializes it with the given id
/// and channel
///
/// @param id the id of the thread
/// @param channel the id of the channel
///
/// @return A pointer to a thread_t struct.
///
thread_t *thread_init(id_t id, char *title, char *body, id_t channel);

///
/// @brief It frees the memory allocated for a team.
/// (It does nothing)
///
/// @param thread The thread object.
///
void thread_destruction(thread_t *thread);
