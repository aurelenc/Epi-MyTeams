/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** team
*/

#include "team.h"
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>

team_t *team_init(id_t id, const char *name)
{
    team_t *team = calloc(sizeof(team_t), 1);

    if (!team) {
        perror("Team creation");
        exit (84);
    }
    team->name = strdup(name);
    if (!team->name) {
        perror("Team creation");
        exit (84);
    }
    return (team);
}

void team_destruction(team_t *team)
{
    if (!team)
        return;
    free(team->name);
}
