/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** users_x_teams
*/

#pragma once

#include "tables/users/user.h"
#include "tables/teams/team.h"

typedef struct id_pair_s
{
    id_t user_id;
    id_t team_id;
}id_pair_t;

///
/// @brief It creates a new id_pair_t structure, fills it with the ids of the
/// given user and team, and returns a pointer to the newly
/// @c created structure
///
/// @param user a pointer to a user_t structure
/// @param team The team to add the user to.
///
/// @return A pointer to a newly @c allocated id_pair_t structure.
///
id_pair_t *create_user_team_relation(user_t *user, team_t *team);

///
/// @brief It takes a pointer to an id_pair_t struct, and frees the memory
/// associated with it
///
/// @param id_pair The id_pair to destroy.
///
void id_pair_destruction(id_pair_t *id_pair);
