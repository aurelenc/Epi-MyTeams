/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** thread
*/

#pragma once

typedef unsigned int id_t;

typedef struct thread_s {
    id_t id;
    id_t start_msg_id;
} thread_t;


///
/// @brief It creates a thread_t structure and initializes it with the given id and
/// start_msg_id
///
/// @param id the id of the thread
/// @param start_msg_id the id of the first message of the thread
///
/// @return A pointer to a thread_t struct.
///
thread_t *thread_init(id_t id, id_t start_msg_id);

///
/// @brief It frees the memory allocated for a team.
/// (It does nothing)
///
/// @param thread The thread object.
///
void thread_destruction(thread_t *thread);
