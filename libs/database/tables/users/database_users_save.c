/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** database_users_save
*/

#include "database.h"
#include "database_users_add.h"
#include "user.h"
#include "tables/load_functions.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

static void write_all_users_in_file(llist_t *users, FILE *fptr)
{
    node_t *nptr = users->first;
    user_t *user;

    while (nptr) {
        user = (user_t *)nptr->data;
        fprintf(fptr, "\"%i\";\"%s\";\"%s\";\"%s\";\n", user->id, user->uuid,
        user->pseudo, user->password);
        nptr = nptr->next;
    }
}

bool db_save_users(database_t *db, const char *filepath)
{
    FILE *fptr;

    fptr = fopen(filepath, "w");
    if (fptr == NULL) {
        printf("Unable to open file.\n");
        return false;
    }
    write_all_users_in_file(db->users, fptr);
    fclose(fptr);
    printf("Users: Successfully saved.\n");
    return true;
}

bool db_load_users(database_t *db, const char *filepath)
{
    char *content = get_file_content(filepath);
    char ***entities = 0;
    user_t *user = 0;

    if (!content)
        return false;
    entities = get_entities(content, 4);
    if (!entities)
        return false;
    for (size_t i = 0; entities[i]; i++) {
        user = user_init(entities[i][2], entities[i][3]);
        free(user->uuid);
        user->uuid = entities[i][1];
        user->id = atoi(entities[i][0]);
        db_add_user(db, user);
    }
    printf("Users: Successfully loaded.\n");
    return true;
}
