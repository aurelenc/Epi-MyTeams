/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** discussion
*/

#pragma once

typedef unsigned int id_t;

typedef struct discussion_s {
    id_t id;
    char *name;
    id_t user_one_id;
    id_t user_two_id;
} discussion_t;


///
/// @brief It creates a discussion
/// structure and returns a pointer to it
///
/// @param id the id of the discussion
/// @param name The name of the discussion.
/// @param user_one_id The id of the first user in the discussion.
/// @param user_two_id The id of the second user in the discussion.
///
/// @return A pointer to a discussion_t struct.
///
discussion_t *discussion_init(id_t id, const char *name,
                              id_t user_one_id, id_t user_two_id);

///
/// @brief It frees the memory allocated for the name of the discussion
///
/// @param discussion The discussion to destroy.
///
/// @return A pointer to a discussion_t struct.
///
void discussion_destruction(discussion_t *discussion);
