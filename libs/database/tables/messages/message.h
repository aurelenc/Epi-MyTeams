/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** message
*/

#pragma once

#include <time.h>

typedef unsigned int id_t;

typedef struct msg_s
{
    id_t id;
    char *uuid;
    char *content;
    time_t timestamp;
    id_t user_id;
    id_t thread_id;
    id_t discussion_id;
} msg_t;

///
/// @brief It creates a message
///
/// @param content the content of the message
/// @param user_id the id of the user who posted the message
/// @param relation an array of 2 integers, the first one is the thread
/// id, the second one is the discussion id.
///
/// @return A pointer to a message structure.
///
msg_t *msg_init(const char *content, id_t user_id, int *relation);

///
/// @brief It frees the memory allocated for the content of the message
///
/// @param msg the message to be destroyed
///
/// @return A pointer to a msg_t struct.
///
void msg_destruction(msg_t *msg);
