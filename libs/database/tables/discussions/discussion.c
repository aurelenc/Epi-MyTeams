/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** discussion
*/

#include "discussion.h"
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

discussion_t *discussion_init(id_t id, const char *name,
                              id_t user_one_id, id_t user_two_id)
{
    discussion_t *discussion = calloc(sizeof(discussion_t), 1);

    if (!discussion) {
        perror("Discussion creation");
        exit (84);
    }
    discussion->id = id;
    discussion->user_one_id = user_one_id;if (!discussion) {
        perror("Discussion creation");
        exit (84);
    }
    discussion->user_two_id = user_two_id;
    discussion->name = strdup(name);
    if (!discussion->name) {
        perror("Discussion creation");
        exit (84);
    }
    return (discussion);
}


void discussion_destruction(discussion_t *discussion)
{
    if (!discussion)
        return;
    free(discussion->name);
    free(discussion);
}
