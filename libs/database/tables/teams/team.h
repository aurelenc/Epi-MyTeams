/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** team
*/

#pragma once

typedef unsigned int id_t;

typedef struct team_s {
    id_t id;
    char *uuid;
    char *name;
    char *desc;
} team_t;

///
/// @brief It creates a team_t structure and initializes it with the given
/// name
///
/// @param name The name of the team.
/// @param name The description of the team.
///
/// @return A pointer to a team_t structure.
///
team_t *team_init(const char *name, const char *desc);

///
/// @brief It frees the memory allocated for the team's name
///
/// @param team the team to destroy
///
/// @return A pointer to a team_t structure.
///
void team_destruction(team_t *team);
