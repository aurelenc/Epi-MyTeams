/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** user
*/

#pragma once

typedef unsigned int id_t;

typedef struct user_s {
    id_t id;
    char *uuid;
    char *pseudo;
    char *password;
} user_t ;

///
/// @brief It creates a user_t structure and initializes it with the given
/// parameters
///
/// @param pseudo The pseudo of the user.
/// @param password the password of the user
///
/// @return A pointer to a user_t structure.
///
user_t *user_init(const char *name, const char *password);

///
/// @brief It frees the memory allocated for the password and pseudo of a user
///
/// @param user the user to destroy
///
/// @return A pointer to a user_t struct.
///
void user_destruction(user_t *user);
