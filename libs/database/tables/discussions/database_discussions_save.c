/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** database_discussions_save
*/

#include "database.h"
#include "database_discussions_add.h"
#include "discussion.h"
#include "tables/load_functions.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

static void write_all_discussions_in_file(llist_t *discussions, FILE *fptr)
{
    node_t *nptr = discussions->first;
    discussion_t *disc;

    while (nptr) {
        disc = (discussion_t *)nptr->data;
        fprintf(fptr,"\"%i\";\"%s\";\"%i\";\"%i\";\n", disc->id, disc->uuid,
        disc->user_one_id, disc->user_two_id);
        nptr = nptr->next;
    }
}

bool db_save_discussions(database_t *db, const char *filepath)
{
    FILE *fptr;

    fptr = fopen(filepath, "w");
    if (fptr == NULL) {
        printf("Unable to open file.\n");
        return false;
    }
    write_all_discussions_in_file(db->discussions, fptr);
    fclose(fptr);
    printf("Discussions saved successfully.\n");
    return true;
}

bool db_load_discussions(database_t *db, const char *filepath)
{
    char *content = get_file_content(filepath);
    char ***entities = 0;
    discussion_t *discussion = 0;

    if (!content)
        return false;
    entities = get_entities(content, 4);
    if (!entities)
        return false;
    for (size_t i = 0; entities[i]; i++) {
        discussion = discussion_init(atoi(entities[i][0]), atoi(entities[i][2]),
        atoi(entities[i][3]));
        free(discussion->uuid);
        discussion->uuid = entities[i][1];
        db_add_discussion(db, discussion);
    }
    return true;
}
