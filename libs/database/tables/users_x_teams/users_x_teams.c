/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** users_x_teams
*/

#include "users_x_teams.h"
#include "user.h"
#include "team.h"

id_pair_t *create_user_team_relation(user_t *user, team_t *team)
{
    id_pair_t *id_pair;

    if (!user || !team)
        return (0);
    id_pair = calloc(sizeof(id_pair_t), 1);
    if (!id_pair) {
        perror("User Team relation creation");
        exit (84);
    }
    id_pair->user_id = user->id;
    id_pair->team_id = team->id;
    return (id_pair);
}

void id_pair_destruction(id_pair_t *id_pair)
{
    if (!id_pair)
        return;
    free(id_pair);
}
