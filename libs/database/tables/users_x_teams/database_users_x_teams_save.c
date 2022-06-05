/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** database_users_x_teams_save
*/

#include "database.h"
#include "database_users_x_teams_add.h"
#include "users_x_teams.h"
#include "tables/load_functions.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

static void write_all_users_x_teams_in_file(llist_t *users_x_teams, FILE *fptr)
{
    node_t *nptr = users_x_teams->first;
    id_pair_t *pair;

    while (nptr) {
        pair = (id_pair_t *)nptr->data;
        fprintf(fptr, "\"%d\";\"%d\";\n", pair->user_id, pair->team_id);
        nptr = nptr->next;
    }
}

bool db_save_users_x_teams(database_t *db, const char *filepath)
{
    FILE *fptr;

    fptr = fopen(filepath, "w");
    if (fptr == NULL) {
        printf("Unable to open file.\n");
        return false;
    }
    write_all_users_x_teams_in_file(db->users_teams, fptr);
    fclose(fptr);
    return true;
}

bool db_load_users_x_teams(database_t *db, const char *filepath)
{
    char *content = get_file_content(filepath);
    char ***entities = 0;
    id_pair_t *relation = 0;

    if (!content)
        return false;
    entities = get_entities(content, 2);
    if (!entities)
        return false;
    for (size_t i = 0; entities[i]; i++) {
        relation = calloc(sizeof(id_pair_t), 1);
        relation->user_id = atoi(entities[i][0]);
        relation->team_id = atoi(entities[i][1]);
        db_add_user_team_relation(db, relation);
    }
    printf("Users - Teams relations: Successfully loaded.\n");
    return true;
}
