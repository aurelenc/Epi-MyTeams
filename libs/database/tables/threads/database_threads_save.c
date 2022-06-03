/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** database_threads_save
*/

#include "database.h"
#include "database_threads_add.h"
#include "thread.h"
#include "tables/load_functions.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

static void write_all_threads_in_file(llist_t *threads, FILE *fptr)
{
    node_t *nptr = threads->first;
    thread_t *thread;

    while (nptr) {
        thread = (thread_t *)nptr->data;
        fprintf(fptr,"\"%i\";\"%s\";\"%s\";\"%s\";\"%d\";\"%ld\";\n",
        thread->id, thread->uuid, thread->title, thread->body,
        thread->channel_id, thread->timestamp);
        nptr = nptr->next;
    }
}

bool db_save_threads(database_t *db, const char *filepath)
{
    FILE *fptr;

    fptr = fopen(filepath, "w");
    if (fptr == NULL) {
        printf("Unable to open file.\n");
        return false;
    }
    write_all_threads_in_file(db->threads, fptr);
    fclose(fptr);
    printf("Threads saved successfully.\n");
    return true;
}

bool db_load_threads(database_t *db, const char *filepath)
{
    char *content = get_file_content(filepath);
    char ***entities = 0;
    thread_t *thread = 0;

    if (!content)
        return false;
    entities = get_entities(content, 6);
    if (!entities)
        return false;
    for (size_t i = 0; entities[i]; i++) {
        thread = thread_init(atoi(entities[i][0]), entities[i][2],
        entities[i][3], atoi(entities[i][4]));
        free(thread->uuid);
        thread->uuid = entities[i][1];
        thread->timestamp = atol(entities[i][5]);
        db_add_thread(db, thread);
    }
    return true;
}
