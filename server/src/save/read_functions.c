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

char *get_file_content(char *filepath)
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

static bool is_entity_start(char *buffer, size_t cursor)
{
    if (!buffer[cursor] || !buffer[cursor + 1])
        return (true);
    return (buffer[cursor] == '[' && buffer[cursor + 1] == '"');
}

static bool is_entity_end(char *buffer, size_t cursor)
{
    if (!buffer[cursor] || !buffer[cursor + 1])
        return (true);
    return (buffer[cursor] == '"' && buffer[cursor + 1] == ']' );
}

char *get_entity(char *buffer)
{
    char *entity = 0;
    size_t len = 0;
    size_t cursor = 0;

    if (!buffer)
        return NULL;
    for (cursor = 0; !is_entity_start(buffer, cursor); cursor++);
    if (!buffer[cursor] || !buffer[cursor + 1])
        return NULL;
    for (cursor += 1; !is_entity_end(buffer, cursor + len); len++);
    if (!buffer[cursor + len] || !buffer[cursor + len + 1])
        return NULL;
    len++;
    entity = calloc(sizeof(char), len + 1);
    if (!entity)
        return NULL;
    strncpy(entity, buffer + cursor, len);
    return entity;
}

char *get_arg(char *entity)
{
    char *arg = 0;
    size_t len = 0;
    size_t cur = 0;

    for (cur = 0; entity[cur] && entity[cur] != '"'; cur++);
    if (!entity[cur])
        return NULL;
    for (cur += 1; entity[cur + len] && entity[cur + len] != '"'; len++);
    if (!entity[cur + len])
        return NULL;
    arg = calloc(sizeof(char), len + 1);
    if (!arg)
        return NULL;
    strncpy(arg, entity + cur, len);
    return arg;
}
