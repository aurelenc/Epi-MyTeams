/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** read_functions
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char *get_file_content(const char *filepath)
{
    char *buffer = 0;
    long length;
    FILE *f = fopen (filepath, "rb");

    if (f) {
        fseek (f, 0, SEEK_END);
        length = ftell (f);
        fseek (f, 0, SEEK_SET);
        buffer = calloc(sizeof(char), length + 1);
        if (buffer) {
            fread (buffer, 1, length, f);
        }
        fclose (f);
    }
    return (buffer);
}

char *get_arg(char *entity, size_t *cur)
{
    char *arg = 0;
    size_t len = 0;

    for (; entity[*cur] && entity[*cur] != '"'; (*cur) += 1);
    if (!entity[*cur])
        return NULL;
    for (*cur += 1; entity[*cur + len] && entity[*cur + len] != '"'; len++);
    if (!entity[*cur + len])
        return NULL;
    arg = calloc(sizeof(char), len + 1);
    if (!arg)
        exit(84);
    strncpy(arg, entity + *cur, len);
    *cur += len + 1;
    return arg;
}

static char**get_an_entity(char *buffer, size_t nb_args, size_t *cursor)
{
    char **entity = calloc(sizeof(char *), nb_args + 1);

    if (!entity)
        exit(84);
    for (size_t arg = 0; buffer[*cursor] && arg < nb_args; arg++) {
        entity[arg] = get_arg(buffer, cursor);
        if (!entity[arg]) {
            free(entity);
            return NULL;
        }
    }
    return entity;
}

char ***get_entities(char *buffer, size_t nb_args)
{
    char ***entities = 0;
    size_t count = 0;
    size_t cursor = 0;

    for (int i = 0; buffer[i]; i++)
        if (buffer[i] == '"')
            count++;
    if (count % 2 != 0 || count % nb_args != 0) {
        printf("Corrupted datas\n");
        return NULL;
    }
    entities = calloc(sizeof(char **), count / nb_args + 1);
    if (!entities)
        exit(84);
    for (size_t i = 0; i < count / nb_args / 2 ; i++) {
        entities[i] = get_an_entity(buffer, nb_args, &cursor);
        if (!entities[i])
            return entities;
    }
    return entities;
}

void free_entities(char ***entities)
{
    for (int i = 0; entities[i]; i++) {
        for (int j = 0; entities[i][j]; j++)
            free(entities[i][j]);
        free(entities[i]);
    }
    free(entities);
}
