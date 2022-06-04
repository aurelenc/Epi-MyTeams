/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** database_teams_save
*/

#include "database.h"
#include "database_teams_add.h"
#include "team.h"
#include "tables/load_functions.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

static void write_all_teams_in_file(llist_t *teams, FILE *fptr)
{
    node_t *nptr = teams->first;
    team_t *team;

    while (nptr) {
        team = (team_t *)nptr->data;
        fprintf(fptr, "\"%i\";\"%s\";\"%s\";\"%s\";\n", team->id, team->uuid,
        team->name, team->desc);
        nptr = nptr->next;
    }
}

bool db_save_teams(database_t *db, const char *filepath)
{
    FILE *fptr;

    fptr = fopen(filepath, "w");
    if (fptr == NULL) {
        printf("Unable to open file.\n");
        return false;
    }
    write_all_teams_in_file(db->teams, fptr);
    fclose(fptr);
    printf("Teams: Successfully saved.\n");
    return true;
}

bool db_load_teams(database_t *db, const char *filepath)
{
    char *content = get_file_content(filepath);
    char ***entities = 0;
    team_t *team = 0;

    if (!content)
        return false;
    entities = get_entities(content, 4);
    if (!entities)
        return false;
    for (size_t i = 0; entities[i]; i++) {
        team = team_init(entities[i][2], entities[i][3]);
        free(team->uuid);
        team->uuid = entities[i][1];
        team->id = atoi(entities[i][0]);
        db_add_team(db, team);
    }
    printf("Teams: Successfully loaded.\n");
    return true;
}
