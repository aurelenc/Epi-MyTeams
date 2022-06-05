/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** database_messages_save
*/

#include "database.h"
#include "database_messages_add.h"
#include "message.h"
#include "tables/load_functions.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

static void write_all_messages_in_file(llist_t *messages, FILE *fptr)
{
    node_t *nptr = messages->first;
    msg_t *msg;

    while (nptr) {
        msg = (msg_t *)nptr->data;
        fprintf(fptr, "\"%i\";\"%s\";\"%s\";\"%ld\";\"%d\";\"%d\";\"%d\";\n",
        msg->id, msg->uuid, msg->content, msg->timestamp, msg->user_id,
        msg->thread_id, msg->discussion_id);
        nptr = nptr->next;
    }
}

bool db_save_msg(database_t *db, const char *filepath)
{
    FILE *fptr;

    fptr = fopen(filepath, "w");
    if (fptr == NULL) {
        printf("Unable to open file.\n");
        return false;
    }
    write_all_messages_in_file(db->messages, fptr);
    fclose(fptr);
    return true;
}

static int *get_relation(char **entity)
{
    int *relation = calloc(sizeof(int), 2);

    if (!relation)
        exit(84);
    relation[0] = atoi(entity[5]);
    relation[1] = atoi(entity[6]);
    return relation;
}

bool db_load_msg(database_t *db, const char *filepath)
{
    char *content = get_file_content(filepath);
    char ***entities = 0;
    msg_t *msg = 0;

    if (!content)
        return false;
    entities = get_entities(content, 7);
    if (!entities)
        return false;
    for (size_t i = 0; entities[i]; i++) {
        msg = msg_init(entities[i][2], atoi(entities[i][4]),
        get_relation(entities[i]));
        free(msg->uuid);
        msg->uuid = entities[i][1];
        msg->id = atoi(entities[i][0]);
        msg->timestamp = atol(entities[i][3]);
        db_add_msg(db, msg);
    }
    printf("Messages: Successfully loaded.\n");
    return true;
}
