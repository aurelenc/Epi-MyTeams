/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** team
*/

#include "team.h"
#include "tables/uuid_gen.h"
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>

team_t *team_init(const char *name, const char *desc)
{
    team_t *team = calloc(sizeof(team_t), 1);

    if (!team)
        exit(84);
    team->id = 0;
    team->uuid = uuid_gen();
    team->name = strdup(name);
    team->desc = strdup(desc);
    if (!team->uuid || !team->name || !team->desc)
        exit(84);
    return (team);
}

void team_destruction(team_t *team)
{
    if (!team)
        return;
    free(team->name);
    free(team->desc);
    free(team);
}
